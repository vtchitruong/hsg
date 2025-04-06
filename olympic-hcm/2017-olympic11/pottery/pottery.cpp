#include <iostream>
#include <vector>

#define input_file "pottery.inp"
#define output_file "pottery.out"

using namespace std;

typedef long long ll;

ll total_time = 0;

// Số lượng thợ nặn và thợ vẽ
int n = 0;
int m = 0;

// Thời gian hoàn thành của mỗi thợ
vector<ll> a;
vector<ll> b;

// Số lần tìm kiếm nhị phân
int number_of_iterations = 60;

double epsilon = 1e-9;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> total_time;
    
    // Đọc dữ liệu thợ nặn
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Đọc dữ liệu thợ vẽ
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
}


// Hàm dùng để tính số sản phẩm tối đa có thể hoàn thành trong thời gian t đối với xưởng nặn hoặc xưởng vẽ
ll possible_products(const vector<ll>& times, int t)
{
    ll result = 0;

    for (int i = 0; i < times.size(); ++i)
    {
        result += (ll)(t / times[i]);
    }

    return result;
}


// Hàm dùng để kiểm tra xem có thể hoàn thành k sản phẩm được không
bool check_k_products(ll k)
{
    if (k == 0) return true;

    // Tìm t1 là thời điểm nhỏ nhất để nặn được k sản phẩm
    double left = 0;
    double right = total_time;

    for (int i = 0; i < number_of_iterations; ++i)
    {
        double mid = left + (right - left) / 2;

        if (possible_products(a, mid) >= k)
            right = mid;
        else
            left = mid;
    }

    double t1 = left;
    
    // Tìm t2 là thời điểm lớn nhất để vẽ được k sản phẩm
    left = 0;
    right = total_time;

    for (int i = 0; i < number_of_iterations; ++i)
    {
        double mid = left + (right - left + 1) / 2;

        if (possible_products(b, total_time - mid) >= k)
            left = mid;
        else
            right = mid;
    }
 
    double t2 = left;
    
    // Trả về kết quả có tồn tại hay không thời điểm t nằm giữa hai thời điểm t1 và t2
    return t1 <= t2 + epsilon;
}


void output()
{
    ll left = 0;
    ll right = 1e18;

    while (left < right)
    {
        ll mid = left + (right - left + 1) / 2;

        if (check_k_products(mid))
            left = mid;
        else
            right = mid - 1;
    }

    freopen(output_file, "w", stdout);
    cout << left << endl;
}


int main()
{   
    input();
    output();

    return 0;
}