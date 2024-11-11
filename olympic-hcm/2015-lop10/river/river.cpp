#include <iostream>
#include <vector>

#define input_file "river.inp"
#define output_file "river.out"

using namespace std;

string River;

// Số lần vượt sông ít nhất để đến được vị trí i ở bờ trái của sông
vector<int> Left;

// Số lần vượt sông ít nhất để đến được vị trí i ở bờ phải của sông
vector<int> Right;

// Số lần vượt sông ít nhất
int result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    cin >> River;
    River = '0' + River;
}


void process()
{
    int n = River.size();
    Left.resize(n);
    Right.resize(n);

    // Khởi tạo vị trí 0 là vị trí xuất phát
    Left[0] = 0;
    Right[0] = 1;

    // Duyệt từng nhánh sông (ký tự của chuỗi River) trong phạm vi [1..n - 1]
    // Xét ba trường hợp: nhánh sông ở bờ trái, ở bờ phải và ở cả hai bờ
    for (int i = 1; i < n; ++i)
    {
        if (River[i] == 'L')
        {
            // Có hai cách đi đến vị trị i ở bờ trái:
            // Cách 1: vượt nhánh sông ở bờ trái
            // Cách 2: vượt sông từ bờ phải sang bờ trái
            Left[i] = min(Left[i - 1] + 1, Right[i - 1] + 1);

            // Có hai cách đi đến vị trị i ở bờ phải:
            // Cách 1: vượt sông từ bờ trái sang bờ phải
            // Cách 2: không vượt lần nào, vì vẫn đang ở bờ phải
            Right[i] = min(Left[i - 1] + 1, Right[i - 1]);
        }
        else if (River[i] == 'R')
        {
            // Có hai cách đi đến vị trị i ở bờ trái:
            // Cách 1: không vượt lần nào, vì vẫn đang ở bờ trái
            // Cách 2: vượt sông từ bờ phải sang bờ trái
            Left[i] = min(Left[i - 1], Right[i - 1] + 1);

            // Có hai cách đi đến vị trị i ở bờ phải:
            // Cách 1: vượt sông từ bờ trái sang bờ phải
            // Cách 2: vượt nhánh sông ở bờ phải
            Right[i] = min(Left[i - 1] + 1, Right[i - 1] + 1);
        }
        else if (River[i] == 'B')
        {
            // Có hai cách đi đến vị trị i ở bờ trái:
            // Cách 1: vượt nhánh sông ở bờ trái
            // Cách 2: vượt nhánh sông ở bờ phải, rồi vượt sông từ bờ phải sang bờ trái
            Left[i] = min(Left[i - 1] + 1, Right[i - 1] + 2);


            // Có hai cách đi đến vị trị i ở bờ phải:
            // Cách 1: vượt nhánh sông ở bờ trái, rồi vượt sông từ bờ trái sang bờ phải
            // Cách 2: vượt nhánh sông ở bờ phải
            Right[i] = min(Left[i - 1] + 2, Right[i - 1] + 1);
        }
    }

    // Bước cuối cùng để đến nhà ngoại
    // Cách 1: vượt sông từ bờ trái sang bờ phải
    // Cách 2: đang ở bờ phải nên không vượt sông nữa
    result = min(Left[n - 1] + 1, Right[n - 1]);
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