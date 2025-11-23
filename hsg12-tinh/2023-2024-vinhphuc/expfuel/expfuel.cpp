#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "expfuel.inp"
#define output_file "expfuel.out"

using namespace std;

typedef long long int lli;

const lli INF = 4e18;

int n, m;

// nhiên liệu cho mỗi đơn vị khoảng cách
lli c;

// Mảng điểm tập kết: first là toạ độ, second là chi phí bay
vector<pair<lli, lli>> A;

// Mảng điểm thám hiểm (điểm đích)
vector<lli> D;

// Mảng dùng để tính prefix min, dành cho các điểm nằm bên trái điểm đích
// Lưu min(b - c * a) từ trái sang
vector<lli> min_left;

// Mảng dùng để tính suffix min, dành cho các điểm nằm bên phải điểm đích
// Lưu min(b + c * a) từ phải sang
vector<lli> min_right;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> m >> c;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i].first >> A[i].second;
    }

    D.resize(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> D[i];
    }
}


// Hàm tiền xử lý
void precompute()
{
    // Sắp xếp điểm tập kết theo toạ độ tăng dần
    sort(A.begin(), A.end());

    // Tính prefix min, càng tiến sang phải càng nhỏ dần
    min_left.resize(n);
    lli current_min = INF;

    for (int i = 0; i < n; ++i)
    {
        lli value = A[i].second  - c * A[i].first;
        current_min = min(current_min, value);
        min_left[i] = current_min;
    }

    // Tính suffix min, càng tiến sang trái càng nhỏ dần
    min_right.resize(n);
    current_min = INF;

    for (int i = n - 1; i > -1; --i)
    {
        lli value = A[i].second + c * A[i].first;
        current_min = min(current_min, value);
        min_right[i] = current_min;
    }
}


// Hàm vừa xử lý vừa in kết quả ra tập tin
void process_output()
{
    freopen(output_file, "w", stdout);

    // Duyệt điểm thám hiểm D[j] của từng đội
    for (int j = 0; j < m; ++j)
    {
        // Khởi tạo output của một đội
        lli answer = INF;

        // Tìm vị trí điểm tập kết đầu tiên nằm bên phải điểm đích D[j]
        auto it = upper_bound(A.begin(), A.end(), D[j],
                [](lli dj, const pair<lli, lli>& a) {
                    return dj < a.first;
                });
        
        // Chuyển đổi iterator sang chỉ số của mảng
        // Chỉ số k là ranh giới
        // - Các điểm từ 0 đến k-1: nằm bên trái hoặc trùng điểm đích (A[i] <= D[j])
        // - Các điểm từ k đến n-1: nằm bên phải đích (A[i] > D[j])
        int k = distance(A.begin(), it);

        // Trường hợp 1: chọn điểm tập kết ở bên trái
        if (k > 0)
        {
            answer = min(answer, min_left[k - 1] + c * D[j]);
        }

        // Trường hợp 2: chọn điểm tập kết ở bên phải
        if (k < n)
        {
            answer = min(answer, min_right[k] - c * D[j]);
        }

        cout << answer << '\n';
    }
}


int main()
{
    input();
    precompute();
    process_output();

    return 0;
}