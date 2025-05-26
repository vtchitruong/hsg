#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define input_file "chonqua.inp"
#define output_file "chonqua.out"

using namespace std;

int n, k;
vector<int> A;
long long int Sum;


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
    // Sắp xếp mảng A theo thứ tự giảm dần
    sort(A.begin(), A.end(), greater<int>());

    // Tính tổng k phần tử đầu
    Sum = accumulate(A.begin(), A.begin() + k, 0);
}


void output()
{   
    freopen(output_file, "w", stdout);

    cout << Sum;
}


int main()
{
    input();
    process();
    output();

    return 0;
}