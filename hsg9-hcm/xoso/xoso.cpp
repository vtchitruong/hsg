#include <iostream>
#include <vector>

#define input_file "xoso.inp"
#define output_file "xoso.out"

using namespace std;

int n, k;
vector<int> A;

typedef long long int lli;
vector<lli> F; // giai thừa (factorial)
vector<lli> invF; // nghịch đảo giai thừa (inverse factorial)
const int MOD = 1e9 + 7; 

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}


void init()
{
    F.resize(n);

    F[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        F[i] = F[i - 1] * i % MOD;
    }

    invF[n] = [] 
}


void process()
{


}


int main()
{
    input();
    init();


    return 0;
}