#include <iostream>
#include <cmath>

#define input_file "matma1.inp"
#define output_file "matma1.out"

using namespace std;

typedef long long int lli;

lli a, n;

lli result = 1;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> a >> n;
}

void process_1()
{
    // Mod 10 để lấy chữ số cuối của a
    a %= 10;

    // Trong khi số mũ n vẫn còn chia đôi được
    while (n > 0)
    {
        if (n & 1)
        {
            // Nếu số mũ lẻ thì chỉ nhân thêm cơ số a vào
            result = (result * a) % 10;
        }

        // Ngược lại, nếu số mũ chẵn thì bình phương cơ số a lên
        a = (a * a) % 10;

        // Chia đôi số mũ
        n >>= 1;
    }
}

void process_2()
{
    // Mod 10 để lấy chữ số cuối của a
    a %= 10;

    // Ánh xạ số mũ n thành số mũ k
    lli k = (n - 1) % 4 + 1;

    result = (lli)pow(a, k) % 10;
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << result;
}

int main()
{
    input();
    // process_1();
    process_2();
    output();

    return 0;
}