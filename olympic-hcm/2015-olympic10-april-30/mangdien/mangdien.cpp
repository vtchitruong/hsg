#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "mangdien.inp"
#define output_file "mangdien.out"

using namespace std;

// Cấu trúc edge biểu thị kết nối giữa hai công ty
struct edge
{
    int a, b, cost;

    bool operator<(const edge& other) const
    {
        return cost < other.cost;
    }

    bool operator==(const edge& other) const
    {
        return a == other.a && b == other.b && cost == other.cost;
    }
};

int n, m;

// Mảng các kết nối
vector<edge> edges;

// rep[a] là đại diện của tập hợp chứa công ty a
// ranking[a] là độ sâu của cây tập hợp chứa công ty a
vector<int> rep, ranking;
int s1, s2;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> m;

    int a, b, cost;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> cost;
        edges.push_back({a, b, cost});
    }
}


// Hàm tìm đại diện của tập hợp chứa công ty a
int find(int a)
{
    if (a != rep[a])
        rep[a] = find(rep[a]);

    return rep[a];
}


// Hàm hợp nhất hai tập hợp chứa công ty a và b
bool unite(int a, int b)
{
    // Lấy đại diện của hai tập hợp chứa a và b
    int rep_a = find(a);
    int rep_b = find(b);

    // Nếu a và b cùng một tập hợp thì không làm gì cả
    if (rep_a == rep_b) return false;

    // Ngược lại, nếu không cùng tập hợp thì hợp nhất hai tập hợp
    if (ranking[rep_a] > ranking[rep_b])
        rep[rep_b] = rep_a;
    else if (ranking[rep_a] < ranking[rep_b])
        rep[rep_a] = rep_b;
    else
    {
        rep[rep_b] = rep_a;
        ranking[rep_a]++;
    }

    return true;
}


// Hàm tìm cây khung nhỏ nhất
int kruskal(vector<edge> &excluded_edges, vector<edge> &included_edges)
{
    // Khởi tạo mảng rep và ranking
    rep.resize(n + 1);
    ranking.resize(n + 1);

    for (int i = 1; i < n + 1; ++i)
    {
        rep[i] = i;
        ranking[i] = 0;
    }

    int total_cost = 0;

    // Duyệt từng kết nối trong input
    for (int i = 0; i < m; ++i)
    {
        // Nếu kết nối đang xét nằm trong mảng loại trừ thì bỏ qua
        if (std::find(excluded_edges.begin(), excluded_edges.end(), edges[i]) != excluded_edges.end())
            continue;

        // Ngược lại, nếu kết nối đang xét không nằm trong mảng loại trừ
        if (unite(edges[i].a, edges[i].b))
        {
            // thì cộng dồn tổng chi phí
            total_cost += edges[i].cost;

            // và thêm vào mảng cây khung nhỏ nhất
            included_edges.push_back(edges[i]);
        }
    }

    // Nếu không đủ n - 1 cạnh thì trả về -1
    if (included_edges.size() != n - 1) return -1;

    return total_cost;
}


// Hàm xử lý bài toán
void process()
{
    // Sắp xếp các kết nối theo chi phí tăng dần
    sort(edges.begin(), edges.end());

    vector<edge> excluded_edges;
    vector<edge> included_edges;

    // Tìm s1
    s1 = kruskal(excluded_edges, included_edges);

    // Tìm s2
    s2 = INT_MAX;
    for (int i = 0; i < included_edges.size(); ++i)
    {
        // Thử loại bỏ kết nối thứ i
        excluded_edges.push_back(included_edges[i]);

        // Mảng lưu cây khung nhỏ nhất mới
        vector<edge> tmp_included_edges;

        // Tính chi phí của cây khung nhỏ nhất mới
        int cost = kruskal(excluded_edges, tmp_included_edges);

        // Xét xem chi phí mới có phải là nhỏ thứ nhì hay không
        if (cost != -1 && cost >= s1)
            s2 = min(s2, cost);

        // Đưa kết nối thứ i trở lại
        excluded_edges.pop_back();
    }

    if (s2 == INT_MAX) s2 = s1;
}


void output()
{
    freopen(output_file, "w", stdout);
    cout << s1 << " " << s2;
}


int main()
{
    input();
    process();
    output();

    return 0;
}