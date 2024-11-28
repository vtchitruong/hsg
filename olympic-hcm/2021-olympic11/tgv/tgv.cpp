#include <iostream>
#include <vector>

#define input_file "tgv.inp"
#define output_file "tgv.out"

using namespace std;

int n;

// Mảng lưu các tung độ có cùng hoành độ x
vector<vector<int>> x_axis;

// Mảng lưu các hoành độ có cùng tung độ y
vector<vector<int>> y_axis;

// số tam giác vuông cần tìm
int result = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;

        if (x >= x_axis.size())
            x_axis.resize(x + 1);

        x_axis[x].push_back(y);

        if (y >= y_axis.size())
            y_axis.resize(y + 1);

        y_axis[y].push_back(x);
    }
}


void process()
{
    // Duyệt từng hoành độ x
    for (int x = 1; x < x_axis.size(); ++x)
    {
        // Nếu tồn tại điểm có hoành độ x đang xét 
        if (x_axis[x].size() != 0)
        {
            // Tính số cạnh song song trục tung, tức có cùng hoàng độ x
            int vertical_edge_number = x_axis[x].size() - 1;

            // Duyệt từng tung độ y có cùng hoành độ x đang xét
            for (int y : x_axis[x])
            {
                // Nếu tồn tại điểm có tung độ y đang xét
                if (y_axis[y].size() != 0)
                {
                    //  Tính số cạnh song song trục hoành, tức có cùng tung độ y
                    int horizontal_edge_number = y_axis[y].size() - 1;

                    // Tính số tam giác vuông tạo thành
                    result += vertical_edge_number * horizontal_edge_number;
                }
            }
        }
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