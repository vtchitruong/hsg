#include <iostream>

#define input_file "phuongtrinh.inp"
#define output_file "phuongtrinh.out"

using namespace std;

int n;
int count_x = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;
}


int sum_digits(int a)
{
    int Sum = 0;
    while (a > 0)
    {
        Sum += a % 10;
        a /= 10;
    }

    return Sum;
}


void process()
{
    // Khởi tạo giá trị xuất phát của nghiệm x
    int start_x = max(1, n - 81);

    // Duyệt từng giá trị x từ start_x đến n
    for (int x = start_x; x < n; ++x)
    {
        if (x + sum_digits(x) == n)
        {
            count_x++;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << count_x;
}


int main()
{
    input();
    process();
    output();

    return 0;
}