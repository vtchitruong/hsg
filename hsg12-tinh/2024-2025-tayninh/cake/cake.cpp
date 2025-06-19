#include <iostream>
#include <limits>
#include <vector>
#include <deque>
#include <algorithm>

#define input_file "cake.inp"
#define output_file "cake.out"

using namespace std;

typedef long long int lli;

// hằng số âm vô cực
const lli INF = numeric_limits<lli>::min();

int n, m, k;
vector<lli> A;

// điểm thưởng cao nhất cần tìm
lli max_score = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n >> m >> k;

    A.resize(n + 1);

    for (int i = 1; i < n + 1; ++i)
    {
        cin >> A[i];
    }
}


void process()
{
    // Khởi tạo bảng quy hoạch động gồm k + 1 lượt chọn (hàng)
    // Mỗi hàng gồm n + 1 điểm thưởng cao nhất (cột)
    // D[choice][cake] là điểm thưởng cao nhất sau choice lượt chọn, kết thúc ở bánh thứ cake
    vector<vector<lli>> D(k + 1, vector<lli>(n + 1, INF));

    // Khởi tạo lượt chọn 1 (hàng 1)
    for (int cake = 1; cake < n + 1; ++cake)
    {
        D[1][cake] = A[cake];
    }

    // Điền bảng quy hoạch động từ lượt (hàng) 2 đến k
    // Duyệt từng lượt chọn (hàng)
    for (int choice = 2; choice < k + 1; ++choice)
    {
        // Khai báo hàng đợi hai đầu lưu chỉ số cake của lượt choice - 1
        deque<int> Q;

        // Duyệt từng bánh (cột)
        for (int cake = 1; cake < n + 1; ++cake)
        {
            if (D[choice - 1][cake - 1] != INF)
            {
                // Loại bỏ các D[][] nhỏ hơn ở cuối hàng đợi (tức bên phải)
                while (!Q.empty() && D[choice - 1][Q.back()] <= D[choice - 1][cake - 1])
                    Q.pop_back();

                // Nạp cake - 1 vào cuối hàng đợi
                Q.push_back(cake - 1);
            }

            // Loại bỏ chỉ số ở đầu hàng đợi Q vì nó nằm ngoài cửa sổ [cake - m, cake - 1]
            if (!Q.empty() && Q.front() < cake - m) Q.pop_front();

            // Tính D[choice][cake]
            if (!Q.empty())
            {
                if (D[choice - 1][Q.front()] != INF)
                    D[choice][cake] = D[choice - 1][Q.front()] + (lli)choice * A[cake];
            }
        }
    }

    // Duyệt các điểm cao nhất trong lượt k (hàng k) để lấy ra kết quả cao nhất
    max_score = *max_element(D[k].begin(), D[k].end());
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_score;
}


int main()
{
    input();
    process();
    output();

    return 0;
}