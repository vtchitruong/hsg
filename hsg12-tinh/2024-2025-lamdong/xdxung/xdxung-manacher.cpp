#include <iosstream>
#include <vector>
#include <string>

#define input_file "xdxung.inp"
#define output_file "xdxung.out"

using namespace std;

string s;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> S;
}


// Tính kích thước chuỗi con palindrome lớn nhất bằng thuật toán Manacher
int manacher()
{
    // Thêm ký tự đặc biệt # vào giữa các ký tự
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }

    // radius[i] dùng để lưu bán kính của chuỗi palindrome dài nhất (), trong đó i là tâm center của chuỗi
    vector<int> radius(t.size(), 0);

    // Biến center dùng để lưu vị trí tâm của chuỗi palindrome hiện hành
    int center = 0;

    // Biến right dùng để lưu vị trí biên phải của chuỗi palindrome mở rộng xa nhất
    int right = 0;

    // Biến max_len dùng để lưu kích thước chuỗi palindrome dài nhất
    int max_len = 0;

    // Duyệt từng ký tự trong chuỗi t (bỏ ký tự ^ ở đầu và $ ở cuối)
    for (int i = 1; i < t.size() - 1; ++i)
    {
        // Nếu i nằm trong phạm vi của chuỗi palindrome hiện hành
        if (i < right)
        { 
            // 2 * center - i là vị trí đối xứng của i qua center
            radius[i] = min(radius[2 * center - i], right - i);
        }

        // Mở rộng chuỗi palindrome hiện hành
        // So sánh ký tự bên trái và bên phải của i để mở rộng chuỗi palindrome
        while (t[i - radius[i] - 1] == t[i + radius[i] + 1])
        {
            radius[i] += 1;
        }

        // Cập nhật center và right nếu chuỗi palindrome mở rộng xa hơn
        if (i + radius[i] > right)
        {
            // Cập nhật tâm mới
            center = i;

            // Cập nhật biên phải mới
            right = i + radius[i];
        }

        // Cập nhật max_len nếu bán kính radius[i] lớn hơn max_len đã biết
        max_len = max(max_len, radius[i]);
    }

    return max_len;
}

int main()
{

    return 0;
}
