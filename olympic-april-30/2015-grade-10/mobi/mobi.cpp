#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "mobi.inp"
#define output_file "mobi.out"

using namespace std;

typedef long long ll;

int n, k;
vector<pair<ll, ll>> locations;
ll max_user_number;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    locations.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> locations[i].first >> locations[i].second;
    }
}


void process()
{
    // Sắp xếp các điểm theo tọa độ x tăng dần
    sort(locations.begin(), locations.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });

    // Biến lưu số lượng người dùng của cửa sổ đang xét
    ll user_number = 0;

    // Biến lưu vị trí bắt đầu cửa sổ
    int left = 0;

    // Duyệt từng khu dân cư bằng mốc phải của cửa sổ
    for (int right = 0; right < n; ++right)
    {
        // Cập nhật số lượng người dùng của cửa sổ
        user_number += locations[right].second;

        // Nếu khoảng cách giữa hai điểm lớn hơn 2k
        while (locations[right].first - locations[left].first > 2 * k)
        {
            // thì giảm số lượng người dùng của cửa sổ
            user_number -= locations[left].second;

            // và tăng vị trí bắt đầu cửa sổ
            ++left;
        }

        // Cập nhật số lượng người dùng lớn nhất
        max_user_number = max(max_user_number, user_number);
    }
}


void output()
{
    freopen(output_file, "w", stdout);
    cout << max_user_number;
}


int main()
{
    input();
    process();
    output();

    return 0;
}