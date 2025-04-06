#include <iostream>

#define input_file "vitinh.inp"
#define output_file "vitinh.out"

using namespace std;

typedef long long int lli;

lli n;
lli total_digits = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;
}


void process()
{
    // các số luỹ thừa của 10: 1, 10, 100, 1000, 10000, ...
    lli power_of_ten = 1;

    // giới hạn trên của phạm vi đang xét: 9, 99, 999, 9999, ...
    lli bound;

    // số chữ số trong phạm vi đang xét: 1, 2, 3, 4, ...
    lli number_of_digits = 1;

    // số lượng số trong phạm vi đang xét
    lli amount;

    while (true)
    {
        // Tính giới hạn trên của phạm vi đang xét: 9, 99, 999, 9999, ...
        bound = power_of_ten * 10 - 1;

        // So sánh n và giới hạn trên
        if (n >= bound)
        {
            // Tính số lượng số trong phạm vi đang xét: 9, 90, 900, 9000, ...
            amount = 9 * power_of_ten;

            // Lấy số lượng số x số chữ số, rồi cộng dồn vào kết quả
            total_digits += amount * number_of_digits;
        }
        else
        {
            // Tính số lượng số trong phạm vi đang xét
            amount = n - power_of_ten + 1;

            // Lấy số lượng số x số chữ số, rồi cộng dồn vào kết quả
            total_digits += amount * number_of_digits;

            // Thoát vòng lặp, kết thúc chương trình
            break;
        }

        // Tăng số chữ số để xét phạm vi tiếp theo
        number_of_digits += 1;

        // Nhân thêm 10
        power_of_ten *= 10;

        // Điều kiện dừng vòng lặp
        if (power_of_ten > n) break;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << total_digits;
}


int main()
{
    input();
    process();
    output();

    return 0;
}