#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "xoso.inp"
#define output_file "xoso.out"

using namespace std;

typedef long long int lli;

const lli M = 1e9 + 7;

int n, k;
vector<int> A;
int s = 0;

vector<vector<lli>> choices;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    if (!(cin >> n >> k))
        return;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}

// Hàm phát sinh các bộ gồm k phiếu bằng phương pháp back tracking
// Đồng thời tính tổng điểm thưởng s với mỗi bộ k phiếu chọn được
void generate(vector<int> &k_choice, int next)
{
    // Trường hợp cơ sở: nếu một bộ đã có đủ k phiếu thì nạp vào choices
    if (k_choice.size() == k)
    {
        // Tính phiếu có giá trị lớn nhất trong bộ gồm k phiếu
        int max_value = *max_element(k_choice.begin(), k_choice.end());

        // Cộng dồn vào tổng điểm thưởng s
        s = (s + max_value) % M;

        return;
    }

    // Phân nhánh: chọn phiếu tiếp theo bằng next
    for (int i = next; i < n; ++i)
    {
        k_choice.push_back(A[i]);
        generate(k_choice, i + 1);

        // Back tracking
        k_choice.pop_back();
    }
}

void process()
{
    vector<int> k_choice;
    int next = 0;

    generate(k_choice, next);
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << s;
}

int main()
{
    input();
    process();
    output();

    return 0;
}