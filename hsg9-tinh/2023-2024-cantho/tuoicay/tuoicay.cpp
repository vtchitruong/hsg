#include <iostream>
#include <vector>

#define input_file "tuoicay.inp"
#define output_file "tuoicay.out"

using namespace std;

int n, k;
vector<int> A;
int max_count = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}


void process()
{
    int left = 0;

    // tổng số nước đã tưới
    int water = 0;

    // Duyệt từng vị trí trong mảng A
    for (int right = 0; right < n; ++right)
    {
        // Cộng dồn tổng số nước đã sử dụng
        water += A[right];

        // Thu hẹp cửa sổ nếu cần
        while (water > k && left <= right)
        {
            water -= A[left];
            left++;
        }

        // Cập nhật số lượng cây nhiều nhất được tưới
        if (water <= k)
        {
            max_count = max(max_count, right - left + 1);
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_count;
}


int main()
{
    input();
    process();
    output();

    return 0;
}