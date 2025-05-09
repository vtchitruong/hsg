#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "trochoi.inp"
#define output_file "trochoi.out"

using namespace std;

typedef long long int lli;

// biến m và n
int number_of_questions, number_of_teams;

// mảng lưu điểm số
vector<vector<int>> a;

// total[i] là tổng điểm của đội i
vector<lli> total;

// điểm số cao nhất
lli max_score = 0;

// đội có điểm số cao nhất
lli max_team = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> number_of_questions >> number_of_teams;

    // Khởi tạo mảng lưu tổng điểm của mỗi đội
    total.resize(number_of_teams, 0);

    int score;

    // Duyệt từng câu hỏi (từng hàng)
    for (int q = 0; q < number_of_questions; ++q)
    {
        // Duyệt từng đội (từng cột)
        for (int t = 0; t < number_of_teams; ++t)
        {
            cin >> score;

            // Cộng dồn điểm cho từng đội
            total[t] += score;
        }
    }
}


void process()
{
    // biến it trỏ vào phần tử lớn nhất trong vector total
    vector<lli>::iterator it = max_element(total.begin(), total.end());

    // Lấy giá trị của phần tử lớn nhất đó
    max_score = *it;

    // Lấy chỉ số (vị trí) của phần tử lớn nhất đó
    max_team = distance(total.begin(), it) + 1;
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_team << ' ' << max_score;
}


int main()
{
    input();
    process();
    output();

    return 0;
}