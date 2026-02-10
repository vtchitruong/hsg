#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>

#define input_file "dulich.inp"
#define output_file "dulich.out"

using namespace std;
using namespace std::chrono;

typedef long long int lli;

const lli INF = 1e18;

int n;
int c[15][15];

// Khai báo mảng hai chiều d gồm 2^15 hàng, 15 cột
// d[mask][u] lưu chi phí nhỏ nhất đi qua các điểm trong mask, kết thúc tại điểm u
lli d[1 << 15][15];

// tổng chi phí nhỏ nhất, dùng để output
lli result = INF;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n;

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            cin >> c[u][v];
        }
    }
}

void process()
{
    // Khởi tạo mảng d gồm toàn giá trị vô cực
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        for (int v = 0; v < n; ++v)
        {
            d[mask][v] = INF;
        }
    }

    // Khởi tạo chi phí 0 cho các điểm xuất phát
    for (int v = 0; v < n; ++v)
    {
        d[1 << v][v] = 0;
    }

    // Duyệt tất cả các trạng thái của mask
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        // Duyệt từng điểm u đang đứng
        for (int u = 0; u < n; ++u)
        {
            // Kiểm tra xem u có nằm trong mask hay không
            if (mask & (1 << u))
            {
                // Kiểm tra xem có đường đi tới u hay không
                if (d[mask][u] == INF)
                    continue;

                // Duyệt điểm v chưa có trong mask, tức thử đi từ u đến v
                for (int v = 0; v < n; ++v)
                {
                    // Nếu chưa ghé thăm điểm v
                    if (!(mask & (1 << v)))
                    {
                        // Đánh dấu v đã được ghé thăm
                        int next_mask = mask | (1 << v);

                        // Tính tổng chi phí mới
                        lli new_cost = d[mask][u] + c[u][v];

                        // Cập nhật chi phí nhỏ hơn
                        if (new_cost < d[next_mask][v])
                        {
                            d[next_mask][v] = new_cost;
                        }
                    }
                }
            }
        }
    }

    // Tìm giá trị nhỏ nhất của tất cả các trạng thái full mask, tức mask = 11...1
    int full_mask = (1 << n) - 1;

    for (int v = 0; v < n; ++v)
    {
        if (d[full_mask][v] < result)
        {
            result = d[full_mask][v];
        }
    }
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << result;
}

int main()
{
    // Bắt đầu bấm giờ (High resolution clock)
    auto start = high_resolution_clock::now();

    input();

    process();

    // Kết thúc bấm giờ
    auto stop = high_resolution_clock::now();

    output();

    // Tính khoảng thời gian
    auto duration = duration_cast<microseconds>(stop - start);

    // In ra kết quả
    cerr << "Thời gian chạy (giây): " << fixed << setprecision(6) << (double)duration.count() / 1000000 << "s" << endl;

    return 0;
}