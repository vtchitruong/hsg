#include <iostream>

#define input_file "songuyento.inp"
#define output_file "songuyento.out"

using namespace std;

int n;
int result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;
}


bool is_prime(int x)
{
    if (x < 1) return false;

    if (x < 4) return true;

    if (x % 2 == 0) return false;

    if (x % 3 == 0) return false;

    for (int i = 5; i * i < x + 1; i += 6)
    {
        if (x % i == 0) return false;
        if (x % (i + 2) == 0) return false;
    }

    return true;
}


void process()
{
    while (true)
    {
        if (is_prime(n))
        {
            result = n;
            break;
        }

        n++;
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