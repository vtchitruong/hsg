#include <iostream>
#include <vector>

#define input_file "chonnguoi.inp"
#define output_file "chonnguoi.out"

using namespace std;

typedef long long int lli;

int n, k;

// biến lưu một tổ hợp
vector<int> C;

// biến đếm số lượng tổ hợp
lli number_of_combinations = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;
}


// Hàm phát sinh tổ hợp
bool combination(vector<int>& A)
{
    // Duyệt từ phần tử cuối ngược về đầu
    for (int i = k - 1; i >= 0; --i)
    {
        // Kiểm tra xem A[i] có thể tăng lên mà vẫn bảo đảm các phần tử sau nó có thể được cập nhật hợp lệ
        // N - (K - i - 1) là giá trị tối đa mà A[i] có thể nhận để sau khi tăng, vẫn còn đủ giá trị lớn hơn cho các phần tử sau
        if (A[i] < n - (k - i - 1))
        {
            A[i]++;

            // Cập nhật các phần tử sau A[i] để chúng là các giá trị nhỏ nhất có thể, mà vẫn lớn hơn phần tử trước đó
            for (int j = i + 1; j < k; ++j)
            {
                A[j] = A[j - 1] + 1;
            }

            // Trả về true nhằm cho biết một tổ hợp mới đã được sinh ra
            return true;
        }
    }

    // Nếu không có phần tử nào có thể tăng, đồng nghĩa tổ hợp hiện tại là tổ hợp cuối cùng
    return false;
}


void process_output()
{
    freopen(output_file, "w", stdout);

    // Khởi tạo bộ ban đầu: 1, 2, 3, ..., k
    C.resize(k);

    for (int i = 0; i < k; ++i)
    {
        C[i] = i + 1;
    }

    // Liệt kê và ghi các tổ hợp ra file
    do
    {
        for (int i = 0; i < k; ++i)
        {
            cout << C[i];
            if (i < k - 1) cout << ' ';
        }

        cout << '\n';
        number_of_combinations++;

    } while (combination(C));
    
    cout << number_of_combinations;
}


int main()
{
    input();
    process_output();
    
    return 0;
}