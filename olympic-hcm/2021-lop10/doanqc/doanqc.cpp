#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define input_file "doanqc.inp"
#define output_file "doanqc.out"

using namespace std;

int n;

// Mỗi phần tử là một cặp số cho biết thời điểm vào và ra {check_in, check_out}
vector<pair<int, int>> customers;

// Mảng lưu lịch phân bố thời điểm phát quảng cáo 
vector<int> ad_schedule;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    int check_in, check_out;
    for (int i = 0; i < n; ++i)
    {
        cin >> check_in >> check_out;
        customers.push_back({check_in, check_out});
    }
}


// Hàm so sánh dùng để tìm thời điểm vào siêu thị nhỏ nhất
bool compare_check_in(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}


// Hàm so sánh dùng để sắp xếp mảng customers theo thời điểm ra khỏi siêu thị
bool compare_check_out(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}


void process()
{
    // Tìm khách hàng đầu tiên, tức có thời điểm đi vào siêu thị nhỏ nhất
    vector<pair<int, int>>::iterator first_customer = min_element(customers.begin(), customers.end(), compare_check_in);

    // Lấy thời điểm vào của khách hàng đầu tiên
    int first_check_in = (*first_customer).first;

    // Lưu thời điểm vào nhỏ nhất vào lịch phân bố
    ad_schedule.push_back(first_check_in);

    // Sắp xếp khách hàng theo thứ tự tăng dần của thời điểm ra
    sort(customers.begin(), customers.end(), compare_check_out);

    // Biến latest_ad lưu thời điểm mới nhất phát quảng cáo
    int latest_ad = -1;

    int check_in, check_out;

    // Duyệt từng khách hàng trong mảng customers đã sắp xếp
    for (pair<int, int> customer : customers)
    {
        // Lấy thời điểm vào và thời điểm ra
        check_in = customer.first;
        check_out = customer.second;
        
        // Nếu thời điểm vào xảy ra sau thời điểm phát quảng cáo mới nhất
        if (latest_ad <= check_in)
        {
            // thì phát quảng cáo tại thời điểm ra
            ad_schedule.push_back(check_out);

            // Ghi nhận thời điểm phát quảng cáo mới nhất
            latest_ad = check_out;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    int s = ad_schedule.size();
    cout << s << '\n';

    for (int i = 0; i < s; ++i)
    {
        cout << ad_schedule[i];
        if (i < s - 1) cout << ' ';
    }
}


int main()
{
    input();
    process();
    output();

    return 0;
}