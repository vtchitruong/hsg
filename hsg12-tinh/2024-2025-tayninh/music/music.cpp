#include <iostream>
#include <vector>
#include <limits>

#define input_file "music.inp"
#define output_file "music.out"

using namespace std;

typedef long long int lli;

int n;
vector<int> A;

// mảng tổng tiền tố prefix_sum
// ps[i] là tổng các phần tử trong đoạn [0..i - 1]
vector<lli> ps;

// độ hấp dẫn lớn nhất cần tìm
lli max_attractive = numeric_limits<lli>::min();


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}


void process()
{
    // Tính mảng tổng tiền tố
    ps.resize(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        ps[i + 1] = ps[i] + A[i];
    }

    // min_ps_even lưu giá trị ps[i - 1] nhỏ nhất, với i - 1 là chẵn.
    // i - 1 = 0 là chẵn, ps[0] = 0
    lli min_ps_even = ps[0];

    // min_ps_odd lưu giá trị ps[i - 1] nhỏ nhất, với i - 1 là lẻ.
    lli min_ps_odd = numeric_limits<lli>::max();

    // Duyệt mảng tổng tiền tố trong đoạn [4..n]
    for (int right = 4; right < n + 1; ++right)
    {
        int k = right - 4;

        // Cập nhật giá trị min_ps_even và min_ps_odd
        if (k % 2 == 0)
            min_ps_even = min(min_ps_even, ps[k]);
        else
            min_ps_odd = min(min_ps_odd, ps[k]);

        // Tính độ hấp dẫn lớn nhất
        if (right % 2 == 0)
        {
            max_attractive = max(max_attractive, ps[right] - min_ps_even);
        }
        else
        {
            if (min_ps_odd != numeric_limits<lli>::max())
                max_attractive = max(max_attractive, ps[right] - min_ps_odd);
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_attractive;
}


int main()
{
    input();
    process();
    output();

    return 0;
}