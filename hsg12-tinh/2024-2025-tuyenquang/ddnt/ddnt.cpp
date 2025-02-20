#include <iostream>
#include <vector>
#include <set>

#define input_file "ddnt.inp"
#define output_file "ddnt.out"

using namespace std;

int n, m, start, finish;

vector<vector<pair<int, int>>> graph;

// D[u] là khoảng cách ngắn nhất từ đỉnh start đến đỉnh u
vector<int> D;

// Sàng nguyên tố
vector<bool> prime;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> m >> start >> finish;

    graph.resize(n + 1);

    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}


// Hàm dùng để tạo sàng nguyên tố trong phạm vi đến 1 triệu lẻ 3
void sieve()
{
    int number = 1E6 + 3;

    // Giả sử mọi số đều nguyên tố
    prime.resize(number + 1, true);
    
    // 0 và 1 không phải số nguyên tố
    prime[0] = false;
    prime[1] = false;

    // Đánh dấu false cho các bội của số nguyên tố p
    for (int p = 2; p * p < number + 1; ++p)
    {
        // Nếu p là nguyên tố thì đánh dấu false cho bội của p
        if (prime[p] == true)
        {
            for (int i = p * p; i < number + 1; i += p)
            {
                prime[i] = false;
            }
        }
    }
}


int increase_to_next_prime(int w)
{
    // Nếu w là số nguyên tố thì trả về 0
    if (prime[w])
        return 0;

    // Tìm số nguyên tố tiếp theo lớn hơn w
    int next_prime = w + 1;
    while (!prime[next_prime])
        ++next_prime;

    return next_prime - w;
}


void dijkstra()
{
    // Mảng D dùng để lưu trữ khoảng cách từ đỉnh start đến các đỉnh còn lại
    D.resize(n + 1, INT_MAX);
    D[start] = 0;

    set<pair<int, int>> q;
    q.insert({0, start});

    // Trong khi q vẫn còn phần tử
    while (!q.empty())
    {
        // Lấy ra đỉnh u có khoảng cách ngắn nhất từ start (vì set đã sắp xếp theo khoảng cách)
        int u = q.begin()->second;

        // Lấy ra khoảng cách ngắn nhất từ start đến u
        int d = q.begin()->first;
        q.erase(q.begin());

        // Dừng thuật toán khi đã đến đích
        if (u == finish)
            break;

        // Nếu đã có một đường đi ngắn hơn từ start đến u thì không cần xét đỉnh u nữa
        if (d > D[u])
            continue;

        // Duyệt từng đỉnh v kề với đỉnh u
        for (int i = 0; i < graph[u].size(); ++i)
        {
            // v là đỉnh kề với u
            int v = graph[u][i].first;

            // w là trọng số của cạnh u -> v
            int w = graph[u][i].second;

            // Tìm giá trị tăng thêm để đạt được số nguyên tố tiếp theo lớn hơn w
            int increase = increase_to_next_prime(w);

            // Nếu có thể đi start -> u -> v nhanh hơn so với start -> v
            if (D[u] + increase < D[v])
            {
                // Nếu v đã có trong q thì xóa phần tử liên quan
                q.erase({D[v], v});

                // Cập nhật lại khoảng cách ngắn nhất từ đỉnh start đến đỉnh v
                D[v] = D[u] + increase;

                // Thêm v vào q với khoảng cách ngắn nhất từ start đến v là d[v]
                q.insert({D[v], v});
            }
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << D[finish];
}


int main()
{
    input();
    sieve();
    dijkstra();
    output();
    
    return 0;
}