#include <iostream>

#define input_file "bangso.inp"
#define output_file "bangso.out"

using namespace std;

typedef long long int lli;

lli n, k;
lli count = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n >> k;
}


void process()
{
    // Duyệt từng chỉ số hàng trong đoạn [1..n]
    for (lli i = 1; i < n + 1; ++i)
    {
        // Nếu k không chia hết cho i thì không
        if (k % i != 0) continue;

        // Tính giá trị cột j
        lli j = k / i;

        // Kiểm tra xem j có nằm trong phạm vi của bảng không (1 <= j <= n)
        if (j <= n) count++;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << count;
}


int main()
{
    input();
    process();
    output();

    return 0;
}