#include <iostream>

#define input_file "chuanhoaxau1.inp"
#define output_file "chuanhoaxau1.out"

using namespace std;

// chuỗi ban đầu
string prop_string;

// chuỗi sau khi biến đổi
string join_string = "";


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    getline(cin, prop_string);
}


void process()
{
    char current;

    // Duyệt từng ký tự trong chuỗi ban đầu
    for (int i = 0; i < prop_string.length(); ++i)
    {
        // ký tự đang xét
        current = prop_string[i];

        // Nếu ký tự đang xét là in hoa
        if (isupper(prop_string[i]))
        {
            // Nếu không phải ký tự in hoa đầu tiên thì thêm gạch
            if (i > 0) join_string += '_';

            // Chuyển ký tự in hoa thành thường
            join_string += tolower(current);
        }
        else
        {
            join_string += current;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << join_string;
}


int main()
{
    input();
    process();
    output();

    return 0;
}