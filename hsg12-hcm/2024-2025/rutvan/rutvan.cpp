#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define input_file "rutvan.inp"
#define output_file "rutvan.out"

using namespace std;

int a, b, n, m;

// Mảng lưu vị trí của các hoành độ (thanh dọc)
vector<int> Xs;

// Mảng lưu vị trí của các tung độ (thanh ngang)
vector<int> Ys;

// Mảng lengths dùng để lưu độ dài của các đoạn được cắt từ các thanh dọc lẫn thanh ngang
vector<int> lengths;

// Tổng độ dài cần tìm
int total_length;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> a >> b >> n >> m;

    // Đọc các hoành độ (thanh dọc)
    Xs.resize(n + 2);

    // Nạp hoành độ đầu tiên là 0
    Xs[0] = 0;

    // Nạp các hoành độ của các thanh dọc
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> Xs[i];
    }

    // Nạp hoành độ cuối cùng là a
    Xs[n + 1] = a;

    // Đọc các tung độ (thanh ngang)
    Ys.resize(m + 2);

    // Nạp tung độ đầu tiên là 0
    Ys[0] = 0;

    // Nạp các tung độ của các thanh ngang
    for (int i = 1; i < m + 1; ++i)
    {
        cin >> Ys[i];
    }

    // Nạp tung độ cuối cùng là b
    Ys[m + 1] = b;
}


void process()
{      
    // Độ dài của một đoạn được cắt
    int l;

    // Duyệt từng vị trí của các hoành độ (thanh dọc)
    for (int i = 1; i < Xs.size(); ++i)
    {
        // Tính độ dài của một đoạn được cắt
        l = Xs[i] - Xs[i - 1];

        // Thêm độ dài vào mảng lengths
        // Số lần thêm phải bằng với số lượng thanh ngang
        for (int j = 0; j < m; ++j)
        {
            lengths.push_back(l);
        }
    }

    // Duyệt từng vị trí của các tung độ (thanh ngang)
    for (int i = 1; i < Ys.size(); ++i)
    {
        // Tính độ dài của một đoạn được cắt
        l = Ys[i] - Ys[i - 1];

        // Thêm độ dài vào mảng lengths
        // Số lần thêm phải bằng với số lượng thanh dọc
        for (int j = 0; j < n; ++j)
        {
            lengths.push_back(l);
        }

    }

    // Sắp xếp mảng lengths tăng dần
    sort(lengths.begin(), lengths.end());

    // Tính số vùng ban đầu
    int region_count = (n + 1) * (m + 1);

    // Tính tổng độ dài của các đoạn được cắt
    // Chỉ lấy số lượng đoạn bằng số vùng trừ đi 1
    total_length = accumulate(lengths.begin(), lengths.begin() + region_count - 1, 0);
}


void output()
{
    freopen(output_file, "w", stdout);
    cout << total_length;
}


int main()
{
    input();
    process();
    output();

    return 0;
}