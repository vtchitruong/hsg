#include <iostream>
#include <vector>

#define input_file "knumber1.inp"
#define output_file "knumber1.out"

using namespace std;

typedef long long int lli;

lli k;
char result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    cin >> k;
}


void process()
{
    // Số lượng chữ số tích luỹ khi tăng độ dài của các số nguyên tạo thành
    lli cumulative_digits = 0;

    // Độ dài (số chữ số) của một số nguyên tạo thành
    int length = 1;

    int integer_amount;
    int digit_amount;
    while (true)
    {
        // Tính số lượng số nguyên tạo thành ứng với độ dài length
        if (length == 1)
        {
            // Với độ dài 1, chỉ có 0 và 5
            integer_amount = 2;
        }
        else
        {
            // Chữ số đầu là 5, các chữ số còn lại là 0 hoặc 5
            integer_amount = 1LL << (length - 1);
        }

        // Số lượng chữ số của nhóm số nguyên có cùng độ dài
        digit_amount = integer_amount * length;

        // Nếu vượt quá vị trí k thì ngắt vòng lặp
        if (cumulative_digits + digit_amount > k) break;

        // Tính số lượng chữ số tích luỹ được và không vượt quá vị trí k
        cumulative_digits += digit_amount;

        // Tăng độ dài để xét nhóm số nguyên tiếp theo
        length += 1;
    }

    // j cũng là vị trí k nhưng xét riêng trong nhóm số nguyên có cùng độ dài length
    lli j = k - cumulative_digits;
    
    // Vị trí của số nguyên liên quan (có chứa vị trí j) tính trong nhóm có cùng độ dài length
    int integer_pos = j / length;

    string integer_string = "";

    // Tạo số nguyên có liên quan
    if (length == 1)
    {
        vector<string> integers = {"0", "5"};
        integer_string = integers[integer_pos];
    }
    else
    {
        // Tạo chữ số đầu tiên, luôn là '5'
        string first_digit = "5";

        // Số chữ số còn lại cần tạo
        int remaining_length = length - 1;
        
        // Tạo chuỗi nhị phân ứng với số nguyên cần tạo
        string binary = "";

        for (int i = remaining_length - 1; i >= 0; --i)
        {
            if (integer_pos & (1LL << i))
            {
                binary += "1";
            }
            else
            {
                binary += "0";
            }
        }

        // Tạo các chữ số còn lại, thay 1 bằng 5
        string remaining_digits = "";
        for (char c : binary)
        {
            if (c == '1')
            {
                remaining_digits += "5";
            }
            else
            {
                remaining_digits += "0";
            }
        }

        // Số nguyên tạo thành ở dạng chuỗi
        integer_string = first_digit + remaining_digits;
    }

    // Chữ số cần tìm
    int target_pos = j % length;
    result = integer_string[target_pos];
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