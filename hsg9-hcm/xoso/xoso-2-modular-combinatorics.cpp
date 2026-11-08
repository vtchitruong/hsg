#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "xoso.inp"
#define output_file "xoso.out"

using namespace std;

typedef long long int lli;

const lli M = 1e9 + 7;

int n, k;
vector<int> A;
lli s = 0;

vector<lli> f;         // giai thừa (factorial)
vector<lli> inverse_f; // nghịch đảo giai thừa

// Hàm tính lũy thừa modular (a^b mod m) bằng phương pháp binary exponentiation
lli power(lli base, lli exp)
{
    lli result = 1;

    base %= M;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % M;

        base = (base * base) % M;
        exp /= 2;
    }

    return result;
}

// Hàm tính nghịch đảo giai thừa modular theo định lý Fermat nhỏ
lli modular_inverse(int x)
{
    return power(x, M - 2);
}

// Hàm tiền tính toán các giá trị giai thừa
void init_factorial()
{
    // Khởi tạo mảng giai thừa và mảng nghịch đảo giai thừa
    f.resize(n + 1, 1);
    inverse_f.resize(n + 1, 1);

    // Tính giai thừa từ 1! đến n!
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (f[i - 1] * i) % M;
    }

    // Tính nghịch đảo modular của n!
    inverse_f[n] = modular_inverse(f[n]);

    // Tính nghịch đảo modular từ (n - 1)! ngược về 0!
    for (int i = n - 1; i >= 0; --i)
    {
        inverse_f[i] = (inverse_f[i + 1] * (i + 1)) % M;
    }
}

// Hàm tính tổ hợp n chập k
lli combinations(int n, int k)
{
    if (k < 0 || k > n)
        return 0;

    lli numerator = f[n];
    lli denominator = (inverse_f[k] * inverse_f[n - k]) % M;

    return (numerator * denominator) % M;
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}

void process()
{
    // Sắp xếp tăng dần giá trị của các phiếu
    sort(A.begin(), A.end());

    // Tiền tính toán
    init_factorial();

    // Tính tổng điểm thưởng s bằng cách tính tổng đóng góp của các phiếu từ phiếu k - 1 cho đến phiếu cuối cùng
    for (int i = k - 1; i < n; ++i)
    {
        // Tính số cách chọn k - 1 phiếu đứng liền trước phiếu A[i]
        lli number_of_combinations = combinations(i, k - 1);

        // Tính tổng đóng góp của phiếu A[i]
        lli contribution = (A[i] * number_of_combinations) % M;

        // Cộng dồn đóng góp của phiếu A[i] vào tổng điểm thưởng s
        s = (s + contribution) % M;
    }
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << s;
}

int main()
{
    input();
    process();
    output();

    return 0;
}