#include <iostream>
#include <vector>
#include <unordered_map>

#define input_file "tgcan.inp"
#define output_file "tgcan.out"

using namespace std;

typedef long long ll;

const int MAX = 100000;
int n;

// Mảng tần số frequency
vector<ll> f(MAX + 1, 0);

// Số tam giác cân
ll result = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    // Vừa đọc input vừa gán giá trị cho mảng tần số f
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        f[x]++;
    }
}


// Hàm dùng để tính tổ hợp C(x, 3) dành cho tam giác đều
ll combination_3(ll x)
{
    if (x < 3) return 0;

    return x * (x - 1) * (x - 2) / 6;
}


// Hàm dùng để tính tổ hợp C(x, 2) dành cho tam giác cân
ll combination_2(ll x)
{
    if (x < 2) return 0;

    return x * (x - 1) / 2;
}


void process()
{
    // Tổng tích luỹ dùng để tính nhanh tổng của f[1]..f[i]
    // prefix[i] = f[1] + f[2] + ... + f[i]
    vector<int> prefix(MAX + 1, 0);

    for (int i = 1; i < MAX + 1; ++i)
    {
        prefix[i] += prefix[i - 1] + f[i];
    }
    
    // Duyệt mảng tần số f
    for (int u = 1; u < MAX + 1; ++u)
    {
        // Tính số tam giác đều
        result += combination_3(f[u]);
    }

    // Duyệt mảng tần số f
    for (int u = 1; u < MAX + 1; ++u)
    {
        // Nếu không đủ hai cạnh để tạo thành tam giác cân thì bỏ qua
        if (f[u] < 2) continue;

        // Tính cận trên của độ dài cạnh thứ ba (cạnh v)
        ll upper_bound = 2LL * u - 1;
        if (upper_bound > MAX) upper_bound = MAX;

        // Tính số cách chọn cạnh thứ ba
        ll count_v = prefix[upper_bound] - f[u];

        // Tính số tam giác cân (u, u, v)
        result += (combination_2(f[u]) * count_v);
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