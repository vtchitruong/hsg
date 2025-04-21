#include <iostream>

#define input_file "latgach.inp"
#define output_file "latgach.out"

using namespace std;

typedef unsigned long long ull;

ull m, n, t;

// độ rộng tối đa cần tìm
ull result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> m >> n >> t;
}


bool check(ull weight)
{
    if (weight == 0) return true;

    // Trường hợp phần không lát gạch không tồn tại
    if (2ULL * weight >= m || 2ULL * weight >= n) return false;

    // Tính số gạch cần lát
    ull tiles = (2ULL * weight) * (m + n - 2ULL * weight);

    return tiles <= t;
}


void process()
{
    ull low = 0;
    ull high = min(m, n) / 2 + 1;

    ull mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (check(mid))
        {
            result = mid;

            // Tiếp tục tìm kiếm phạm vi bên phải nhằm tìm ra giá trị mid (weight) lớn nhất
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
    input();
    process();
    output();

    return 0;
}