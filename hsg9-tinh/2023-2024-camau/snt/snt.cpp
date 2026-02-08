#include <iostream>
#include <vector>
#include <bitset>

#define input_file "snt.inp"
#define output_file "snt.out"

using namespace std;

const int MAX = 1E7;

int n, l, r;

// Biến e lưu sàng Eratosthenes
bitset<MAX + 1> e;

// prime_count[i] lưu số lượng số nguyên tố từ 1 đến i
vector<int> prime_count(MAX + 1, 0);

// Hàm khởi tạo sàng nguyên tố Eratosthenes
void sieve()
{
    // Khỏi tạo toàn bộ bit đều là 1
    e.set();

    // 0 và 1 không phải số nguyên tố
    e[0] = 0;
    e[1] = 0;

    // Duyệt từng số p trong phạm vi [2..sqrt(MAX)]
    for (int p = 2; p * p < MAX + 1; ++p)
    {
        if (e[p])
        {
            // Nếu p là số nguyên tố thì đánh dấu 0 cho các bội của p, bắt đầu từ p * p
            for (int i = p * p; i < MAX + 1; i += p)
            {
                e[i] = 0;
            }
        }
    }
}

// Hàm tính mảng cộng dồn (prefix sum)
void prefix_sum()
{
    for (int i = 1; i < MAX + 1; ++i)
    {
        prime_count[i] = prime_count[i - 1] + e[i];
    }
}

// Hàm vừa đọc input vừa xuất kết quả
void process()
{
    // Khởi tạo sàng nguyên tố e
    sieve();

    // Tính mảng cộng dồn prime_count
    prefix_sum();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    freopen(output_file, "w", stdout);

    cin >> n;

    int result;
    for (int q = 0; q < n; ++q)
    {
        cin >> l >> r;

        // Dựa vào prefix sum, in ra số lượng số nguyên tố trong phạm vi [l, r]
        result = prime_count[r] - prime_count[l - 1];
        cout << result << '\n';
    }
}

int main()
{
    process();

    return 0;
}