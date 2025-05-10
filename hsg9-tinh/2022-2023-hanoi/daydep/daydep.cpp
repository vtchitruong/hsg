#include <iostream>
#include <vector>
#include <deque>

#define input_file "daydep1.inp"
#define output_file "daydep1.out"

using namespace std;

const int MAX = 1e5;

int n;
vector<int> A;

// mảng tần số lưu số lần xuất hiện của một phần tử A[i] trong cửa sổ trượt [left..right]
vector<int> f(MAX + 1, 0);

// biến lưu số lượng dãy con cần tìm
long long int count;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    A.resize(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}


void process()
{
    // vị trí bắt đầu của cửa sổ trượt
    int left = 0;

    // Duyệt từng vị trí kết thúc cửa sổ trượt
    for (int right = 0; right < n; ++right)
    {
        // Thêm A[right] vào cửa sổ và cập nhật số lần xuất hiện
        f[A[right]]++;

        // Di chuyển con trỏ trái để loại bỏ phần tử trùng nhau
        while (left <= right && f[A[right]] > 1)
        {
            f[A[left]]--;
            left++;
        }

        // Cửa sổ [left..right] hiện không còn phần tử trùng nhau
        
        // Khai báo deque dùng để tìm phần tử nhỏ nhất trong dãy con [k..right]
        // deque lưu chỉ số k thoả điều kiện các A[k] trong deque tăng dần
        deque<int> dq_min;

        // Khai báo deque dùng để tìm phần tử lớn nhất trong dãy con [k..right]
        // deque lưu chỉ số k thoả điều kiện các A[k] trong deque giảm dần
        deque<int> dq_max;

        // Duyệt từng vị trí k, từ right ngược về left
        for (int k = right; k >= left; --k)
        {
            // Cập nhật dq_min sao cho tăng dần
            while (!dq_min.empty() && A[dq_min.back()] >= A[k])
                dq_min.pop_back();

            // Nạp chỉ số k hợp lệ vào cuối hàng
            dq_min.push_back(k);

            // Cập nhật dq_max sao cho giảm dần
            while (!dq_max.empty() && A[dq_max.back()] <= A[k])
                dq_max.pop_back();

            // Nạp chỉ số k hợp lệ vào cuối hàng
            dq_max.push_back(k);

            // Kiểm tra [k..right] có phải là dãy đẹp hay không
            if (A[dq_max.front()] - A[dq_min.front()] == right - k) count++;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);
    
    cout << count;
}


int main()
{
    input();
    process();
    output();

    return 0;
}