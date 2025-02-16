#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "bomchum.inp"
#define output_file "bomchum.out"

using namespace std;

typedef long long ll;

const ll MAX = 1000000000000;

int q;
vector<ll> A;

static ll sum_of_divisors[MAX + 1];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> q;

    A.resize(q);

    for (int i = 0; i < q; ++i)
    {
        cin >> A[i];
    }
}


void process()
{
    fill_n(sum_of_divisors, MAX + 1, 1);

    int max_A = *max_element(A.begin(), A.end());

    for (ll a = 2; a < max_A + 1; ++a)
    {
        for (ll j = a; j < max_A + 1; j += a)
        {
            sum_of_divisors[j] += a;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 0; i < q; ++i)
    {
        cout << sum_of_divisors[A[i]];

        if (i != q - 1) cout << ' ';
    }
}


int main()
{
    input();
    process();
    output();

    return 0;
}