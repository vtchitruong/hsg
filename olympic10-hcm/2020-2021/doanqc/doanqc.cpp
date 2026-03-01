#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "doanqc.inp"
#define output_file "doanqc.out"

using namespace std;

int n;

struct interval
{
    int checkin;
    int checkout;
};

// mỗi phần tử là một cặp số cho biết thời điểm vào và ra {checkin, checkout}
vector<interval> customers;

// mảng lưu các thời điểm phát quảng cáo
vector<int> schedule;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    customers.resize(n);

    int checkin, checkout;
    for (int i = 0; i < n; ++i)
    {
        cin >> customers[i].checkin >> customers[i].checkout;
    }
}

// Hàm so sánh dùng để tìm thời điểm vào siêu thị nhỏ nhất
bool compare_checkin(const interval &a, const interval &b)
{
    return a.checkin < b.checkin;
}

// Hàm so sánh dùng để sắp xếp mảng customers theo thời điểm ra
bool compare_checkout(const interval &a, const interval &b)
{
    return a.checkout < b.checkout;
}

void process()
{
    // Tìm khách hàng đầu tiên, tức thời điểm đi vào siêu thị nhỏ nhất
    vector<interval>::iterator first_customer = min_element(customers.begin(), customers.end(), compare_checkin);

    // Lưu thời điểm vào nhỏ nhất vào lịch
    schedule.push_back((*first_customer).checkin);

    // Sắp xếp khách hàng theo thứ tự tăng dần đối với thời điểm ra
    sort(customers.begin(), customers.end(), compare_checkout);

    // biến latest_ad lưu thời điểm mới nhất phát quảng cáo
    int latest_ad = -1;

    int checkin, checkout;

    // Duyệt từng khách hàng trong mảng customers đã sắp xếp
    for (interval c : customers)
    {
        // Nếu thời điểm vào xảy ra sau thời điểm phát quảng cáo mới nhất
        if (latest_ad <= c.checkin)
        {
            // thì phát quảng cáo tại thời điểm ra
            schedule.push_back(c.checkout);

            // Ghi nhận thời điểm phát quảng cáo mới nhất
            latest_ad = c.checkout;
        }
    }
}

void output()
{
    freopen(output_file, "w", stdout);

    int s = schedule.size();
    cout << s << '\n';

    for (int i = 0; i < s; ++i)
    {
        cout << schedule[i];
        if (i < s - 1)
            cout << ' ';
    }
}

int main()
{
    input();
    process();
    output();

    return 0;
}