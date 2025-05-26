#include <iostream>
#include <string>
#include <algorithm>

#define input_file "matthu.inp"
#define output_file "matthu.out"

using namespace std;

int n;
string encoded;
string decoded = "";


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n;
    cin >> encoded;
}


// Hàm dùng để đảo ngược chuỗi
string reverse_string(string s)
{
    reverse(s.begin(), s.end());
    return s;
}


void process()
{
    string word = "";
    char digit = ' '; // ký tự khoảng trắng

    // Duyệt từng ký tự trong chuỗi encoded
    for (int i = 0; i < n; ++i)
    {
        // Nếu ký tự đang xét là 1 hoặc 2
        if (encoded[i] == '1' || encoded[i] == '2')
        {
            // Nếu word hiện hành khác rỗng
            if (!word.empty())
            {
                // thì giữ nguyên hoặc đảo chuỗi
                if (digit == '1')
                    decoded += word;
                else if (digit == '2')
                    decoded += reverse_string(word);

                // Nếu decoded khác rỗng thì thêm ký tự khoảng trắng
                if (!decoded.empty())
                    decoded += " ";

                // Khởi tạo lại word rỗng
                word = "";
            }

            digit = encoded[i];
        }
        else
        {
            // Ngược lại, nếu không phải ký tự số thì ghép ký tự đang xét vào word
            word += encoded[i];
        }
    }

    // Xử lý từ cuối cùng
    if (!word.empty())
    {
        if (digit == '1')
            decoded += word;
        else if (digit == '2')
            decoded += reverse_string(word);
    }

    // Loại bỏ ký tự khoảng trắng ở cuối nếu có
    if (!decoded.empty() && decoded.back() == ' ')
        decoded.pop_back();
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << decoded;
}


int main()
{
    input();
    process();
    output();

    return 0;
}