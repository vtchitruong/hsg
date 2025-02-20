#include <iostream>
#include <vector>

#define input_file "trochoi1.inp"
#define output_file "trochoi1.out"

using namespace std;

int n, k, q;

// Mảng tần số xuất hiện của các học sinh từ 1 đến n
vector<int> f;

// Mảng lưu học sinh tham gia trò chơi
vector<int> students;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k >> q;

    // Khởi tạo mảng tần số f
    f.resize(n + 1, 0);

    int l, r;
    for (int i = 0; i < k; ++i)
    {
        cin >> l >> r;

        // Tăng tần số xuất hiện của các học sinh từ l đến r lên 1
        for (int j = l; j <= r; ++j)
            f[j]++;
    }

    // Đọc các học sinh cần kiểm tra
    students.resize(q + 1);

    int b;
    for (int i = 1; i < q + 1; ++i)
    {
        cin >> students[i];
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 1; i < q + 1; ++i)
    {
        // In ra số lượng trò chơi mà học sinh students[i] tham gia
        cout << f[students[i]];
        if (i != q) cout << '\n';
    }
}


int main()
{
    input();
    output();
    
    return 0;
}