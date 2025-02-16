#include <iostream>
#include <vector>

#define input_file "xdxung.inp"
#define output_file "xdxung.out"

using namespace std;

string s;

// D[i][j] lưu giá trị true/false đối với chuỗi con s[i..j]
vector<vector<bool>> D;

int max_len = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> s;
}


void process()
{
    // Khởi tạo mảng D
    int n = s.length();
    D.resize(n, vector<bool>(s.size(), false));

    // Khởi tạo D[i][i] cho tất cả chuỗi con có độ dài bằng 1
    for (int i = 0; i < n; ++i)
    {
        D[i][i] = true;
    }

    // Khởi tạo D[i][i+1] cho tất cả chuỗi con có độ dài bằng 2 với hai ký tự giống nhau
    for (int i = 0; i < n - 1; ++i)
    {
        D[i][i + 1] = (s[i] == s[i + 1]);
    }

    // Duyệt từng độ dài, với độ dài từ 3 trở lên
    for (int length = 3; length <= n; ++length)
    {
        // Duyệt từng vị trí i, là vị trí bắt đầu của chuỗi con
        for (int i = 0; i < n - length + 1; ++i)
        {
            // j là vị trí kết thúc của chuỗi con
            int j = i + length - 1;

            // Nếu ký tự đầu và cuối của chuỗi con giống nhau và chuỗi con bên trong là đối xứng
            if (s[i] == s[j])
                if (D[i + 1][j - 1] == true)
                {
                    // thì chuỗi con [i..j] cũng là đối xứng
                    D[i][j] = true;

                    // Cập nhật lại max_len nếu độ dài chuỗi con đối xứng đang xét lớn hơn max_len
                    max_len = max(max_len, length);
                }
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_len;
}


int main()
{
    input();
    process();
    output();

    return 0;
}
