#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "doxingau.inp"
#define output_file "doxingau.out"

using namespace std;

int s1, s2, s3;
vector<int> counter;
int result;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> s1 >> s2 >> s3;
}

void process()
{
    // Khởi tạo mảng tần số
    counter.resize(s1 + s2 + s3 + 1, 0);

    // Duyệt từng mặt của từng xí ngầu
    for (int i = 1; i <= s1; ++i)
    {
        for (int j = 1; j <= s2; ++j)
        {
            for (int k = 1; k <= s3; ++k)
            {
                // Tăng số lần xuất hiện của tổng thêm 1
                counter[i + j + k]++;
            }
        }
    }

    // Tìm vị trí của phần tử lớn nhất
    auto it = max_element(counter.begin(), counter.end());

    // Lấy chỉ số của phần tử lớn nhất, cũng chính là tổng của 3 xí ngầu
    result = distance(counter.begin(), it);
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