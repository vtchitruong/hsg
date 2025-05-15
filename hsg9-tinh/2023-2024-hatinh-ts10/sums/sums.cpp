#include <iostream>

using namespace std;

#define inputFile "sums2.inp"
#define outputFile "sums2.out"

typedef long long int lli;

lli n;
lli S;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen(inputFile, "r", stdin);
    cin >> n;
}


void process()
{
    S = n * (n + 2);
}


void output()
{
    freopen(outputFile, "w", stdout);

    cout << S;
}


int main()
{
    input();
    process();
    output();

    return 0;
}