#include <iostream>

#define input_file "banhtrungthu.inp"
#define output_file "banhtrungthu.out"

using namespace std;

int m, n;
int result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> m;
    cin >> n;
}


void process()
{
    // Số lượng giá trị k chia hết cho m mà không vượt quá n
    int count_n_m = n / m;

    // Số lượng giá trị k +  1 chia hết cho m mà không vượt quá n
    int count_n_1_m = (n + 1) / m;
    
    // Số lượng cần tìm
    result = count_n_m + count_n_1_m;
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