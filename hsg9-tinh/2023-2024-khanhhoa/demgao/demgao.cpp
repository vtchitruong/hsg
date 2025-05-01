#include <iostream>

#define input_file "demgao.inp"
#define output_file "demgao.out"

using namespace std;

typedef long long int lli;

lli a, b, k;
lli count_multiples;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> a >> b >> k;
}


void process()
{
    // Số lượng bội của k trong phạm vi [1..b]
    lli count_b_k = b / k;

    // Số lượng bội của k trong phạm vi [1..a - 1]
    lli count_a_1_k = (a - 1) / k; 

    // Số lượng bội của k trong phạm vi [a..b]
    count_multiples = count_b_k - count_a_1_k;
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << count_multiples;
}


int main()
{
    input();
    process();
    output();

    return 0;
}