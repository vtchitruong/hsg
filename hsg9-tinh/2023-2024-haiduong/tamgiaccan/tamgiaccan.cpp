#include <iostream>

#define input_file "tamgiaccan.inp"
#define output_file "tamgiaccan.out"

using namespace std;

int a, b;
int c;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    
    cin >> a;

    cin >> b;
}


void process()
{
    c = max(a, b);
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << c;
}


int main()
{
    input();
    process();
    output();

    return 0;
}