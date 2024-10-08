#include <iostream>

#define inputFile "bnum4.inp"
#define outputFile "bnum4.out"

using namespace std;

string n;
int prime;
int sum_digit; // tổng các chữ số

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(inputFile, "r", stdin);
    cin >> n;
}


// Hàm kiểm tra số nguyên tố
bool isPrime(int n)
{
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    // Kiểm tra n có chia hết cho 5, 7, 11, 13, 17, 19, v.v...
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }

    return true;
}


void process()
{
    sum_digit = 0;
    int digit;

    // Duyệt từng chữ số trong chuỗi n
    for (char c : n)
    {
        // Chuyển đổi chữ số thành số
        digit = c - '0';

        // Tính tổng bình phương
        sum_digit += digit * digit;
    }

    if (isPrime(sum_digit))
    {
        prime = 1;
    }
    else
    {
        prime = -1;
    }
}


void output()
{
    freopen(outputFile, "w", stdout);
    cout << prime << '\n' << sum_digit;
}


int main()
{
    input();
    process();
    output();

    return 0;
}