#include <iostream>
#include <vector>

#define input_file "squery.inp"
#define output_file "squery.out"

using namespace std;

int n, q;
vector<int> A;
vector<int> result;

// Hàm dùng để đếm số phần tử là ước hoặc bội của d
int count_dm(int l, int r, int d)
{
    int cnt = 0;

    // Duyệt mảng A từ vị trí l đến vị trí r
    for (int i = l; i < r +  1; ++i)
    {
        // Xét A[i] là ước hoặc bội của d
        if (A[i] % d == 0 || d % A[i] == 0)
        {
            cnt += 1;
        }
    }

    return cnt;
}


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> q;

    // Cấp phát bộ nhớ cho n + 1 phần tử (vì mảng A đánh chỉ số từ 1)
    A.resize(n + 1);

    for (int i = 1; i < n + 1; ++i)
    {
        cin >> A[i];
    }

    // Gọi hàm count_dm để đếm ước và bội
    int l, r, d;
    int cnt ;
    for (int i = 0; i < q; ++i)
    {
        cin >> l >> r >> d;

        cnt = count_dm(l, r, d);
        result.push_back(cnt);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    int s = result.size();

    for (int i = 0; i < s; ++i)
    {
        cout << result[i];
        if (i < s - 1) cout << ' ';
    }
}


int main()
{
    input();
    output();

    return 0;
}