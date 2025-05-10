#include <iostream>

#define input_file "palindrome.inp"
#define output_file "palindrome.out"

using namespace std;

string s;

// độ dài lớn nhất cần tìm
int max_length = 1;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    getline(cin, s);
}


void process()
{
    int n = s.length();

    int left, right;
    int tmp_length;

    // Duyệt từng ký tự của s
    for (int i = 0; i < n; ++i)
    {
        // Kiểm tra chuỗi đối xứng có độ dài lẻ
        left = i;
        right = i;

        // Nếu hai đầu left và right giống nhau
        while (left >= 0 && right < n && s[left] == s[right])
        {
            // thì tính độ dài từ left đến right
            tmp_length = right - left + 1;

            // Cập nhật độ dài lớn nhất
            max_length = max(max_length, tmp_length);
            
            // Tiếp tục mở rộng hai bên
            --left;
            ++right;
        }

        // Kiểm tra chuỗi đối xứng có độ dài chẵn
        left = i;
        right = i + 1;

        // Nếu hai đầu left và right giống nhau
        while (left >= 0 && right < n && s[left] == s[right])
        {
            // thì tính độ dài từ left đến right
            tmp_length = right - left + 1; 

            // Cập nhật độ dài lớn nhất
            max_length = max(max_length, tmp_length);

            // Tiếp tục mở rộng hai bên
            --left;
            ++right;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_length;
}


int main()
{
    input();
    process();
    output();

    return 0;
}