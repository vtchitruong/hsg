#include <iostream>

#define input_file "gacho.inp"
#define output_file "gacho.out"

using namespace std;

typedef long long int lli;

lli n;
lli result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;
}


void process()
{
    lli k = (n - 1) / 2;

    result = k * (n - k - 1);
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