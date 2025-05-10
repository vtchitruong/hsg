#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

#define input_file "ngaycong.inp"
#define output_file "ngaycong.out"

using namespace std;

int n;
vector<int> days;

int total;
float average;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    days.resize(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> days[i];
    }
}


void process()
{
    // Sắp xếp ngày công giảm dần
    sort(days.begin(), days.end(), greater<int>());

    // Tính tổng số ngày
    total = accumulate(days.begin(), days.end(), 0);

    // Tính trung bình cộng
    average = (float) total / days.size();
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 0; i < n; ++i)
    {
        cout << days[i] << ' ';
    }

    cout << '\n';

    cout << total << ' ' << fixed << setprecision(2) << average;
}


int main()
{
    input();
    process();
    output();

    return 0;
}