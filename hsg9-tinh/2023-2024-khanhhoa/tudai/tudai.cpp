#include <iostream>
#include <sstream>

#define input_file "tudai.inp"
#define output_file "tudai.out"

using namespace std;

string line;
string longest_word;
int max_length = 0;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    getline(cin, line);
}


void process()
{
    // Khởi tạo stringstream từ chuỗi line
    stringstream ss(line);

    string word;

    // Đọc từng từ trong ss vào word
    while (ss >> word)
    {
        int len = word.length();
        if (len >= max_length)
        {
            max_length = len;
            longest_word = word;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_length << '\n' << longest_word;
}


int main()
{
    input();
    process();
    output();

    return 0;
}