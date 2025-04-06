#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define input_file "chiphi.inp"
#define output_file "chiphi.out"

using namespace std;

typedef long long int lli;

const lli INF = 1e18;

struct node
{
    int id;
    int travel_cost;
};

// số nút, số nút, số truy vấn
int n, m, r;

// Mảng lưu nút và chi phí hành trình T
vector<lli> T;

// Mảng lưu nút và chi phí hành trình T để tìm giá trị lớn nhất
vector<node> nodes;

// Mảng lưu chi phí lưu thông L giữa hai nút
vector<vector<lli>> L;

// Mảng lưu các truy vấn (là các cặp nút)
vector<pair<int, int>> queries;

// mảng lưu kết quả tổng chi phí nhỏ nhất giữa hai cặp nút (dành cho các truy vấn)
vector<vector<lli>> results;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> m >> r;

    // Đọc chi phí hành trình T
    T.resize(n + 1);
    nodes.resize(n);
    for (int i = 0; i < n; ++i)
    {
        nodes[i].id = i + 1;
        cin >> nodes[i].travel_cost;
        T[i + 1] = nodes[i].travel_cost;
    }

    // Khởi tạo mảng chi phí lưu thông L
    L.resize(n + 1, vector<lli>(n + 1, INF));

    // Khởi tạo mảng kết quả
    results.resize(n + 1, vector<lli>(n + 1, INF));

    // Khởi tạo cho trường hợp một nút đi đến chính nó
    for (int i = 1; i < n + 1; ++i)
    {
        L[i][i] = 0;
        results[i][i] = T[i];
    }

    // Đọc chi phí lưu thông l giữa hai nút i và k
    int i, k;
    lli l, initial_total_cost;
    for (int u = 0; u < m; ++u)
    {
        cin >> i >> k >> l;

        L[i][k] = l;
        L[k][i] = l;

        // Tạm tính tổng chi phí ban đầu 
        initial_total_cost = l + max(T[i], T[k]);
        results[i][k] = initial_total_cost;
        results[k][i] = initial_total_cost;
    }

    // Khởi tạo mảng các truy vấn
    queries.resize(r);

    // Đọc các cặp nút cần truy vấn
    int u_query, v_query;
    for (int i = 0; i < r; ++i)
    {
        cin >> u_query >> v_query;
        queries[i] = {u_query, v_query};
    }
}


// Hàm so sánh dùng để sắp xếp các nút theo thứ tự chi phí hành trình tăng dần
bool compare(const node &a, const node &b)
{
    return a.travel_cost < b.travel_cost;
}


void process()
{
    // Sắp xếp các nút theo chi phí hành trình tăng dần
    sort(nodes.begin(), nodes.end(), compare);

    // nút trung gian k và phí hành trình t tại nút k 
    int k, tk;

    // Duyệt từng nút theo thứ tự vừa sắp xếp ở trên
    for (int p = 0; p < n; ++p)
    {
        // Xét nút trung gian k và chi phí hành trình tại k
        k = nodes[p].id;
        tk = nodes[p].travel_cost; 
    
        // Duyệt từng cặp nút u - v
        for (int u = 1; u < n + 1; ++u)
        {
            for (int v = 1; v < n + 1; ++v)
            {
                // 1. Tính chi phí lưu thông khi đi qua nút trung gian k
                if (L[u][k] != INF && L[k][v] != INF)
                {
                    L[u][v] = min(L[u][v], L[u][k] + L[k][v]);
                }

                // 2. Tính tổng chi phí kết quả tốt nhất (nếu có đường đi từ u đến v)
                if (L[u][v] != INF)
                {
                    results[u][v] = min(results[u][v], L[u][v] + max({T[u], T[v], T[k]}));
                }
            }
        }

        // Bảo đảm tính đối xứng cho mảng results sau mỗi bước k
        for (int u = 1; u < n + 1; ++u)
        {
            for (int v = u + 1; v < n + 1; ++v)
            {
                results[u][v] = min(results[u][v], results[v][u]);
                results[v][u] = results[u][v];
            }
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    int u, v;
    for (int i = 0; i < r; ++i)
    {
        u = queries[i].first;
        v = queries[i].second;

        cout << results[u][v] << '\n';
    }
}


int main()
{
    input();
    process();
    output();

    return 0;
}