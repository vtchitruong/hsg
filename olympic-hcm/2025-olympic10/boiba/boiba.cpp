#include <iostream>

#define input_file "boiba.inp"
#define output_file "boiba.out"

using namespace std;

typedef long long int lli;

int n;

// tổng giá trị cần cộng cho các phần tử
lli result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    // phần tử a[i] của input
    lli ai;

    // phần tử a[i] sau khi cộng thêm để chia hết cho 3
    lli new_ai;

    // Giá trị tích luỹ từ các phần tử trước đó dùng để cộng thêm cho phần tử tiếp theo
    lli cumulative = 0;

    // Duyệt các phần tử từ đầu đến cuối
    for (int i = 0; i < n; ++i)
    {
        // Đọc từng phần tử từ tập tin input
        cin >> ai;

        // Tính a[i] sau khi cộng thêm giá trị tích luỹ để chia hết cho 3 
        new_ai = ai + cumulative;

        // Tính số dư khi chia cho 3
        lli remain = new_ai % 3;

        // Tính giá trị x cần cộng thêm để chia hết cho 3
        lli x = 0;
        if (remain != 0) x = 3 - remain;

        // x > 0 nghĩa là cần phải cộng thêm x cho phần tử tiếp theo
        if (x > 0)
        {
            // Cập nhật tổng giá trị cần cộng cho phần tử, bao gồm a[i] và tất cả phần tử sau a[i]
            result += x * (n - i);

            // Cập nhật giá trị tích luỹ nhằm cộng cho phần tử tiếp theo ở vòng lặp kế tiếp
            cumulative += x;
        }
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