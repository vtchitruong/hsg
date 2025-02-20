#include <iostream>
#include <vector>

#define input_file "tinhtong.inp"
#define output_file "tinhtong.out"

using namespace std;

int n;

// Tổng cần tìm
int result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen(input_file, "r", stdin);

    cin >> n;
    
    int a;

    // Đọc từng số của input
    for (int i = 0; i < n; ++i)
    {
        cin >> a;

        // Kiểm tra thoả điều kiện và cộng dồn
        if (a % 10 > a / 10 % 10)
            result += a;
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
    output();

    return 0;
}