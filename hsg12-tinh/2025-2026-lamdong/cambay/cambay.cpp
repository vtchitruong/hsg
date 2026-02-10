#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "cambay.inp"
#define output_file "cambay.out"

using namespace std;

const int INF = 2e9;

int n, m;
vector<int> matrix;

int min_value = INF;
int max_value = -1;

int result;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n >> m;

    matrix.resize(n * m, 0);

    // Đọc dữ liệu và chuyển đổi luôn sang mảng một chiều
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            int i = r * m + c;
            cin >> matrix[i];

            // Tìm giá trị nhỏ nhất
            if (matrix[i] < min_value)
                min_value = matrix[i];

            // Tìm giá trị lớn nhất
            if (matrix[i] > max_value)
                max_value = matrix[i];
        }
    }
}

void process()
{
    vector<bool> trap_rows(n, false);
    vector<bool> trap_cols(m, false);

    int value;

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            // Lấy ra giá trị tại hàng r, cột c
            value = matrix[r * m + c];

            if (value == min_value || value == max_value)
            {
                // Nếu giá trị lấy ra bằng nhỏ nhất hoặc lớn nhất
                // thì đánh dấu hàng r, cột c có bẫy
                trap_rows[r] = true;
                trap_cols[c] = true;
            }
        }
    }

    // Đếm số hàng không có bẫy
    int no_trap_row_count = count(trap_rows.begin(), trap_rows.end(), false);

    // Đếm số cột không có bẫy
    int no_trap_col_count = count(trap_cols.begin(), trap_cols.end(), false);

    result = no_trap_row_count * no_trap_col_count;
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