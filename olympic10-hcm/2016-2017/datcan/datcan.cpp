#include <iostream>
#include <vector>

#define input_file "datcan.inp"
#define output_file "datcan.out"

using namespace std;

typedef long long int lli;

int n;
vector<int> p;
lli result;

// tổng khối lượng các quả cân
int total = 0;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n;

    p.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];

        total += p[i];
    }
}

void process()
{
    // Khởi tạo mảng prev_d để lưu số cách ở bước trước đó
    vector<lli> prev_d(2 * total + 1, 0);

    // Chưa đặt quả cân nào lên đĩa, tính là 1 cách
    prev_d[total] = 1;

    // Duyệt từng quả cân
    for (int i = 0; i < n; ++i)
    {
        int w = p[i];

        vector<lli> d(2 * total + 1, 0);

        // Duyệt từng mức độ chênh lệch khối lượng của hai đĩa
        for (int j = 0; j < 2 * total + 1; ++j)
        {
            if (prev_d[j] > 0)
            {
                // Trường hợp 0: không đặt thêm quả cân
                d[j] += prev_d[j];

                // Trường hợp 1: đặt quả cân w lên đĩa trái
                if (j + w < 2 * total + 1)
                    d[j + w] += prev_d[j];

                // Trường hợp 2: đặt quả cân w lên đĩa phải
                if (j - w >= 0)
                    d[j - w] += prev_d[j];
            }
        }

        // Cập nhật mảng d để chuẩn bị cho lần lặp tiếp theo
        prev_d = d;
    }

    result = (prev_d[total] - 1) / 2;
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