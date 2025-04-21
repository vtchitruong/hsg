#include <iostream>

#define input_file "nangluong.inp"
#define output_file "nangluong.out"

using namespace std;

int n, a, b;
int p; // số ngày luyện tập cần tìm


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    freopen(input_file, "r", stdin);

    cin >> n >> a >> b;
}


void process()
{
    int numerator = n * a; 
    int denominator = a + b;

    if (numerator % denominator == 0)
    {
        p = numerator / denominator;
    }
    else
    {
        p = -1;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << p;
}


int main()
{
    input();
    process();
    output();

    return 0;
}