#include <iostream>

#define input_file "tongchuso.inp"
#define output_file "tongchuso.out"

using namespace std;

int n;
int Sum = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;
}


void process()
{
    while (n > 0)
    {
        Sum += n % 10;
        n /= 10;
    }
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