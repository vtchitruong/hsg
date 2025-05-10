#include <iostream>

#define input_file "matma.inp"
#define output_file "matma.out"

using namespace std;

int mom_day, mom_month, mom_year;
int dad_day, dad_month, dad_year;

// mật mã cần tìm
int code;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> mom_day >> mom_month >> mom_year;

    cin >> dad_day >> dad_month >> dad_year;
}


// Hàm tìm ước chung lớn nhất
int gcd(int a, int b)
{
    while (b > 0)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}


void process()
{
    int mom_sum = mom_day + mom_month + mom_year;

    int dad_sum = dad_day + dad_month + dad_year;

    int g = gcd(mom_sum, dad_sum);

    code = mom_sum / g * dad_sum;
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << code; 
}


int main()
{
    input();
    process();
    output();

    return 0;
}