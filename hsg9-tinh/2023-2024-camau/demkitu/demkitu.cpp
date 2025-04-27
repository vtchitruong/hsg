#include <iostream>
#include <cstring>

#define input_file "demkitu.inp"
#define output_file "demkitu.out"

using namespace std;

string s;

// mảng tần số f (frequency) lưu số lần xuất hiện của các ký tự
int f[26] = {};


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen(input_file, "r", stdin);

    getline(cin, s);
}


void process()
{
    // Duyệt từng ký tự của chuỗi s
    for (int i = 0; i < s.length(); i++)
    {
        // Ứng với ký tự s[i], cập nhật số lần xuất hiện của nó
        f[s[i] - 'a']++;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 0; i < 26; i++)
    {
        if (f[i] != 0)
            cout << (char)(i + 'a') << " " << f[i] << '\n';
    }
}


int main()
{
    input();
    process();
    output();

    return 0;
}