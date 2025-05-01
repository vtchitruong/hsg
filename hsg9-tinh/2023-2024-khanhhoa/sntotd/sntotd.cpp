#include <iostream>
#include <vector>

#define input_file "sntotd.inp"
#define output_file "sntotd.out"

using namespace std;

// 10^6 * 10 + 9 < 10^7 + 10
const int MAX = 1e7 + 10;

int n;
vector<int> A;
int m;

// Khởi tạo mảng prime để lưu trữ sàng Eratosthenes
vector<char> prime(MAX + 1, 1);

// Mảng chứa các kết quả
vector<int> results;


// Hàm tạo sàng Eratosthenes
void sieve()
{
    // 0 và 1 không phải nguyên tố
    prime[0] = 0;
    prime[1] = 0;

    // Duyệt các số từ 2 trở đi
    for (int p = 2; p * p < MAX; ++p)
    {
        // Nếu p là số nguyên tố
        if (prime[p] == 1)
        {
            // thì đánh dấu 0 (false) cho các bội số của p
            for (int i = p * p; i < MAX; i += p)
            {
                prime[i] = 0;
            }
        }
    }
}


// Hàm kiểm tra điều kiện 1:
inline bool check_1(int x)
{
    // Kiểm tra x có phải là nguyên tố không
    return prime[x] == 1;
}


// Hàm kiểm tra điều kiện 2
inline bool check_2(int x)
{
    int tmp = x / 10;

    // Lần lượt bỏ chữ số bên phải mà vẫn còn nguyên tố
    while (tmp > 0)
    {
        if (prime[tmp] == 0) return false;
        tmp /= 10;
    }

    return true;
}


// Hàm kiểm tra điều kiện 3: thêm chữ số vào bên phải
inline bool check_3(int x)
{
    // Thêm chữ số vào bên phải và số mới vẫn là nguyên tố
    for (int d = 0; d <= 9; ++d)
    {        
        int tmp = x * 10 + d;

        if (tmp <= MAX)
        {
            if (prime[tmp] == 1) return true;
        }
    }

    return false;
}


// Hàm kiểm tra số nguyên tố toàn diện
bool is_comprehensive_prime(int x)
{
    if (check_1(x) == false) return false;
    
    if (check_2(x) == false) return false;

    if (check_3(x) == false) return false;

    return true;
}


void input_process()
{
    // Khởi tạo sàng Eratosthenes
    sieve();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    // Khởi tạo mảng A
    A.resize(n + 1);

    // Khởi tạo mảng tổng cộng dồn (prefix sum)
    // count_cp[i] lưu số lượng số nguyên tố toàn diện trong phạm vi [1..i]
    vector<int> count_cp(n + 1, 0);

    // Duyệt mảng A
    for (int i = 1; i < n + 1; ++i)
    {
        // Đọc từng phần tử của A
        cin >> A[i];

        // Cập nhật mảng cộng dồn
        count_cp[i] = count_cp[i - 1] + (is_comprehensive_prime(A[i]) ? 1 : 0);
    }

    cin >> m;

    // Khởi tạo mảng chứa kết quả
    results.resize(m, 0);

    int u, v;

    // Duyệt từng truy vấn [u, v]
    for (int i = 0; i < m; ++i)
    {
        // Đọc truy vấn
        cin >> u >> v;

        // Cập nhật kết quả của từng truy vấn dựa trên mảng tổng cộng dồn
        results[i] = count_cp[v] - count_cp[u - 1]; 
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 0; i < m; ++i)
    {
        cout << results[i] << '\n';
    }
}


int main()
{
    input_process();
    output();

    return 0;
}