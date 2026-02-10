#include <iostream>

#define input_file "xaucon.inp"
#define output_file "xaucon.out"

using namespace std;

string s;
int result;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> s;
}

// Hàm kiểm tra nguyên âm
bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void process()
{
    int vowel = 0;
    int consonant = 0;

    // Duyệt chuỗi để đếm số nguyên âm và số phụ âm
    for (int i = 0; i < s.length(); ++i)
    {
        if (is_vowel(s[i]))
            ++vowel;
        else
            ++consonant;
    }

    // Tính số chuỗi con đặc biệt
    result = vowel * consonant;
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