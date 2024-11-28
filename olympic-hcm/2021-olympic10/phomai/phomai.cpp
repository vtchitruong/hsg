#include <iostream>

#define input_file "phomai4.inp"
#define output_file "phomai4.out"

using namespace std;

int a, b;
int result;

struct factors
{
    int x = 0; // số mũ của 2
    int y = 0; // số mũ của 3
    int z = 0; // số mũ của 5
    int remaining = 0; // phần dư sau khi phân tích luỹ thừa
};


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> a >> b;
}


// Hàm dùng để phân tích số n thành thừa số nguyên tố 2, 3 và 5
factors factorize(int n)
{
    factors f;

    // Chia 2 nhiều lần để lấy số mũ của 2
    while (n % 2 == 0)
    {
        n /= 2;
        f.x += 1;
    }

    // Chia 3 nhiều lần để lấy số mũ của 3
    while (n % 3 == 0)
    {
        n /= 3;
        f.y += 1;
    }

    // Chia 5 nhiều lần để lấy số mũ của 5
    while (n % 5 == 0)
    {
        n /= 5;
        f.z += 1;
    }

    // Phần dư còn lại của n
    f.remaining = n;

    return f;
}


void process()
{
    // Phân tích a và b
    factors fa = factorize(a);
    factors fb = factorize(b);

    // Nếu phần dư không bằng nhau thì có nghĩa là không có cách chia
    if (fa.remaining != fb.remaining)
    {
        result = -1;
        return; 
    }

    // Ngược lại, nếu phần dư bằng nhau thì tính tổng các chênh lệch giữa các số mũ
    result = abs(fa.x - fb.x) + abs(fa.y - fb.y) + abs(fa.z - fb.z);
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