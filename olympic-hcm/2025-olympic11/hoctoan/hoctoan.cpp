#include <iostream>
#include <math.h>

#define input_file "hoctoan.inp"
#define output_file "hoctoan.out"

using namespace std;

int a, b;
int x, y;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen(input_file, "r", stdin);
    
    cin >> a >> b;
}


// Hàm tìm ước chung lớn nhất
int gcd(int u, int v)
{
    while (u != 0)
    {
        int r = v % u;
        v = u;
        u = r;
    }

    return v;
}


void process()
{
    if (b % a != 0)
    {
        x = -1;
        return;
    }
    else
    {
        int p = b / a;

        int y1;

        // tổng x1 + y1 đang xét
        int current_sum;

        // biến min_sum lưu tổng x1 + y1 nhỏ nhất
        int min_sum = numeric_limits<int>::max();

        // Duyệt từng ước x1 của p (p = b/a)
        for (int x1 = 1; x1 * x1 < p; ++x1)
        {
            // Nếu x1 là ước của p
            if (p % x1 == 0)
            {
                // thì tìm ước còn lại y1
                y1 = p / x1;

                // Nếu x1 và y1 nguyên tố cùng nhau
                if (gcd(x1, y1) == 1)
                {
                    // thì tính tổng x1 + y1
                    current_sum = x1 + y1;

                    // Cập nhật tổng nhỏ nhất
                    if (current_sum < min_sum)
                    {
                        min_sum = current_sum;
                        x = a * x1;
                        y = a * y1;
                    }
                }
            }
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    if (x == -1)
    {
        cout << -1;
    }
    else
    {
        int s = x + y;
        cout << s << '\n'; 
        cout << x << ' ' << y;  
    }
}

int main()
{
    input();
    process();
    output();

    return 0;
}
