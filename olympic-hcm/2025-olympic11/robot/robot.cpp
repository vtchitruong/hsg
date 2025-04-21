#include <iostream>
#include <vector>

#define input_file "robot.inp"
#define output_file "robot.out"

using namespace std;

int m, n;

// đường đi của robot 1 và robot 2
string path_1, path_2;

// mảng lưu các ô mà robot 1 và robot 2 đã đi qua
vector<vector<bool>> visited_1;
vector<vector<bool>> visited_2;

// số ô mà cả hai robot cùng đi qua
int result = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> m >> n;

    cin >> path_1 >> path_2;
}


void process()
{
    // Khởi tạo mảng visited_1 lưu các ô mà robot 1 đã đi qua
    visited_1.resize(m, vector<bool>(n, false));

    // Toạ độ hiện hành của robot 1
    int r1 = 0;
    int c1 = 0;
    visited_1[r1][c1] = true;

    // Khởi tạo mảng visited_2 lưu các ô mà robot 2 đã đi qua
    visited_2.resize(m, vector<bool>(n, false));

    // Toạ độ hiện hành của robot 2
    int r2 = m - 1;
    int c2 = n - 1;
    visited_2[r2][c2] = true;
    
    // Duyệt từng ký tự trong chuỗi hành trình
    for (int i = 0; i < path_1.length(); ++i)
    {
        // Cập nhật toạ độ mới của robot 1
        if (path_1[i] == 'D')
            r1 += 1;
        else
            c1 += 1;

        // Đánh dấu ô mà robot 1 đã đi qua
        if (r1 > -1)
            if (r1 < m)
                if (c1 > -1)
                    if (c1 < n)
                        visited_1[r1][c1] = true;

        // Cập nhật toạ độ mới của robot 2
        if (path_2[i] == 'U')
            r2 -= 1;
        else
            c2 -= 1;

        // Đánh dấu ô mà robot 2 đã đi qua
        if (r2 > -1)
            if (r2 < m)
                if (c2 > -1)
                    if (c2 < n)
                        visited_2[r2][c2] = true;
    }

    // Đếm số ô mà cả hai robot cùng đi qua
    for (int r = 0; r < m; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            if (visited_1[r][c])
                if (visited_2[r][c])
                    result += 1;
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