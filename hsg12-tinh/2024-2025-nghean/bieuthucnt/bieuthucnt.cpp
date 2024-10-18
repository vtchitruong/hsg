#include <iostream>
#include <vector>

#define input_file "bieuthucnt.inp"
#define output_file "bieuthucnt.out"

using namespace std;

int n;
vector<char> S; // sàng Eratosthenes

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;
}


// Hàm tạo sàng nguyên tố Eratosthenes
void sieve()
{
    // Giả sử tất cả đều là số nguyên tố
    S.resize(3 * n + 1, 1);

    // 0 và 1 không phải nguyên tố
    S[0] = S[1] = 0;

    // Duyệt từ 2 đến 3n
    for (int i = 2; i * i < 3 * n + 1; ++i)
    {
        // Nếu i là nguyên tố
        if (S[i] == 1)
        {
            // thì các bội j của i đang xét không còn nguyên tố nữa
            for (int j = i * i; j < 3 * n + 1; j += i)
            {
                S[j] = 0;         
            }
        }
    }
}


int process()
{
    sieve();

    int cnt = 0;
    int p;

    // Duyệt tất cả x và y
    for (int x = 1; x < n + 1; ++x)
    {
        for (int y = 1; y < n + 1; ++y)
        {
            p = x + 2 * y;
            if (S[p] == 1) cnt += 1;
        }
    }

    return cnt;
}


void output()
{
    int res = process();
    freopen(output_file, "w", stdout);
    cout << res;
}

int main()
{
    input();
    output();
    return 0;
}