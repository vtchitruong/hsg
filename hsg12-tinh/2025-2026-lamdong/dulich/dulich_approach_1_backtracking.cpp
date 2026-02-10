#include <iostream>
#include <climits>

#define input_file "dulich.inp"
#define output_file "dulich.out"

using namespace std;

typedef long long int lli;

int n;
int c[16][16];

// mảng đánh dấu các điểm du lịch đã đi qua
bool visited[16];

// chi phí nhỏ nhất của một cạnh bất kỳ, dùng cho kỹ thuật nhánh cận
lli c_min = LLONG_MAX;

// chi phí tối ưu, dùng để output
lli result = LLONG_MAX;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n;

    for (int u = 1; u < n + 1; ++u)
    {
        for (int v = 1; v < n + 1; ++v)
        {
            cin >> c[u][v];

            if (u != v && c[u][v] < c_min)
            {
                c_min = c[u][v];
            }
        }
    }
}

void traverse(int u, int counter, lli c_current)
{
    // Nếu chi phí hiện tại + (số cạnh còn thiếu * giá cạnh nhỏ nhất) >= kết quả thì cắt nhánh
    if (c_current + (n - counter + 1) * c_min >= result)
        return;

    // Nếu đã đi qua đủ n địa điểm
    if (counter == n)
    {
        if (c_current < result)
            result = c_current;

        return;
    }

    for (int v = 1; v < n + 1; ++v)
    {
        if (!visited[v])
        {
            // Thử ghé thăm điểm v
            visited[v] = true;

            traverse(v, counter + 1, c_current + c[u][v]);

            // quay lui
            visited[v] = false;
        }
    }
}

void process()
{
    // Thử xuất phát từ mọi địa điểm
    for (int u = 1; u < n + 1; ++u)
    {
        visited[u] = true;

        // Xuất phát từ điểm u, số điểm đã ghé thăm là 1, tổng chi phí là 0
        traverse(u, 1, 0);

        visited[u] = false;
    }
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << result;
}

int main()
{
    input();
    process();
    output();

    return 0;
}