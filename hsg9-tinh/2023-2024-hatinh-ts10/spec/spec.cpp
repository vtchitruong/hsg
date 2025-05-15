#include <iostream>
#include <vector>

#define inputFile "spec2.inp"
#define outputFile "spec2.out"

using namespace std;

int n;
vector<char> A;
int max_consecutive = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(inputFile, "r", stdin);

    cin >> n;

    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;

        if (x > 0)
            A.push_back(1);
        else
            A.push_back(0);
    }
}


int process()
{
    // Khởi tạo hai bộ đếm dương và âm
    int count_positive = 0;
    int count_negative = 0;

    // Khởi tạo độ dài lớn nhất cho dãy âm và dương
    int max_positive = 0;
    int max_negative = 0;

    // Duyệt từng phần tử của mảng A
    for (char a : A)
    {
        // Tăng 1 cho bộ đếm tương ứng với âm hoặc dương
        // và gán 0 cho bộ đếm còn lại
        if (a == 1)
        {
            count_positive += 1;
            count_negative = 0;
        }
        else
        {
            count_positive = 0;
            count_negative += 1;
        }

        // Ghi nhận hai độ dài lớn nhất
        max_positive = max(max_positive, count_positive);
        max_negative = max(max_negative, count_negative);
    }

    return max(max_positive, max_negative);
}


void output()
{
    int res = process();
    
    freopen(outputFile, "w", stdout);
    cout << res;
}


int main()
{
    input();
    output();

    return 0;
}