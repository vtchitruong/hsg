#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "expfuel.inp"
#define output_file "expfuel.out"

using namespace std;

int n, m, c;
vector<pair<int, int>> A;
vector<int> D;
vector<int> result;


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


// Hàm tính tổng nhiên liệu bao gồm đường bay và đường bộ
int fuel(int flying_fuel, int ai, int dj)
{
    return flying_fuel + c * abs(ai - dj);
}


void process()
{
    int min_fuel;

    // Duyệt điểm thám hiểm dj của các đội
    for (int j = 0; j < m; ++j)
    {
        min_fuel = INT_MAX; 

        // Duyệt các điểm tập kết a_i của đội dj đang xét
        for (const pair<int, int>& a : A)
        {
            min_fuel = min(min_fuel, fuel(a.second, a.first, D[j]));
        }

        result.push_back(min_fuel);    
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int j = 0; j < m; ++j)
    {
        cout << result[j] << '\n';
    }
}


int main()
{
    input();
    process();
    output();

    return 0;
}