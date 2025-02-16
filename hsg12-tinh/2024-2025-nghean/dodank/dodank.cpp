#include <iostream>
#include <vector>

#define input_file "dodank1.inp"
#define output_file "dodank1.out"

using namespace std;

int n, k;
vector<int> A;
long long int result = 0;
int m = 1000000007;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        A.push_back(a);
    }
}


void process()
{
    // for (int i = 0; i < n; ++i)
    // {
    //     result += A[i];
    //     result %= m;
    // }

    long long int sum;
    for (int i = 0; i < n; ++i)
    {
        for (int d = k; d <= n - i; ++d)
        {
            sum = 0;

            for (int j = i; j < n; j += d)
            {
                sum += A[j];
                sum %= m;

                result += sum;
                result %= m;
            }
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << result;
}


int main()
{
    input();
    process();
    output();

    return 0;
}