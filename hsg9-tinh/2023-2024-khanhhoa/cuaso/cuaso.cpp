#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "cuaso.inp"
#define output_file "cuaso.out"

using namespace std;

const int MAX = 1e6;

int n;

// mảng tần số lưu số lần xuất hiện của một độ dài a[i]
vector<int> f(MAX + 1, 0);

// chu vi lớn nhất
int max_perimeter = -1;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    int length;

    // Đọc từng độ dài và cập nhật số lần xuất hiện của từng độ dài
    for (int i = 0; i < n; ++i)
    {
        cin >> length;
        f[length]++;
    }
}


void process()
{
    // mảng lưu các độ dài ứng viên
    vector<int> candidates;

    // Duyệt mảng tần số f
    for (int length = 1; length < MAX + 1; ++length)
    {
        // Nếu độ dài có hơn 2 que thì nạp độ dài này vào mảng ứng viên
        if (f[length] >= 2)
        {
            candidates.push_back(length);
        }

        // Nếu độ dài có hơn 4 que thì nạp độ dài này vào mảng ứng viên lần nữa
        if (f[length] >= 4)
        {
            candidates.push_back(length);
        }
    }

    // Nếu mỗi độ dài ứng viên có đủ 2 loại trở lên
    if (candidates.size() > 1)
    {
        // thì sắp xếp các độ dài giảm dần
        sort(candidates.rbegin(), candidates.rend());

        // Tính chu vi lớn nhất
        max_perimeter = 2 * (candidates[0] + candidates[1]);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_perimeter;
}


int main()
{
    input();
    process();
    output();

    return 0;
}