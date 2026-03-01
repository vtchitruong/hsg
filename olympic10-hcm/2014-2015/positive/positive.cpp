#include <iostream>
#include <vector>
#include <queue>

#define input_file "positive.inp"
#define output_file "positive.out"

using namespace std;

struct cell
{
    int r;
    int c;
};

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> visited;

// 8 hướng di chuyển
vector<cell> directions = {
    {-1, 0}, // lên
    {0, 1},  // phải
    {1, 0},  // xuống
    {0, -1}, // trái
    {-1, 1}, // phải trên
    {1, 1},  // phải dưới
    {1, -1}, // trái dưới
    {-1, -1} // trái trên
};

int region_count = 0;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> R >> C;

    grid.resize(R, vector<int>(C));

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            cin >> grid[r][c];
        }
    }
}

void bfs(cell start)
{
    // Khởi tạo hàng đợi q
    queue<cell> q;
    q.push(start);
    visited[start.r][start.c] = true;

    // Duyệt lưới grid theo BFS và đánh dấu các ô đã duyệt qua
    while (!q.empty())
    {
        // Lấy ô nằm ở đầu ra khỏi hàng đợi
        cell current = q.front();
        q.pop();

        for (const cell &d : directions)
        {
            // Lấy giá trị của ô tiếp theo
            cell next = {current.r + d.r, current.c + d.c};

            // Kiểm tra xem ô next có thỏa các điều kiện sau không:
            // 1. nằm trong lưới
            // 2. có giá trị dương
            // 3. chưa đánh dấu
            if (next.r >= 0 && next.r < R && next.c >= 0 && next.c < C && grid[next.r][next.c] > 0 && !visited[next.r][next.c])
            {
                // Đánh dấu ô next
                visited[next.r][next.c] = true;

                // Đẩy ô next vào hàng đợi
                q.push(next);
            }
        }
    }
}

void process()
{
    // Khởi tạo mảng visited
    visited.assign(R, vector<bool>(C, false));

    // Duyệt từng ô trong lưới grid
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (grid[r][c] > 0 && !visited[r][c])
            {
                // Nếu ô có giá trị dương và chưa đánh dấu thì bắt đầu tính là một vùng mới
                region_count += 1;

                // Thực hiện bfs từ ô này
                bfs({r, c});
            }
        }
    }
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << region_count;
}

int main()
{
    input();
    process();
    output();

    return 0;
}