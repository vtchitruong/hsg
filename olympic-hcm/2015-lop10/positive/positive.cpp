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
    {0, 1}, // phải
    {1, 0}, // xuống
    {0, -1}, // trái
    {-1, 1}, // phải trên     
    {1, 1}, // phải dưới     
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

    cell current; // ô đang xét
    cell next;    // ô lân cận

    // Duyệt lưới grid theo BFS và đánh dấu đã duyệt cho tất cả ô trong cùng một vùng
    while (!q.empty())
    {
        current.r = q.front().r;
        current.c = q.front().c;
        q.pop();

        visited[current.r][current.c] = true;

        for (int d = 0; d < directions.size(); ++d)
        {
            // Lấy giá trị của ô next
            next.r = current.r + directions[d].r;
            next.c = current.c + directions[d].c;

            // Kiểm tra xem ô next có thoả các điều kiện sau không:
            // 1. nằm trong lưới
            // 2. có giá trị dương
            // 3. chưa duyệt
            if (next.r > -1)
                if (next.r < R)
                    if (next.c > -1)
                        if (next.c < C)
                            if (grid[next.r][next.c] > 0)
                                if (visited[next.r][next.c] == false)
                                {
                                    // Đánh dấu ô next đã duyệt
                                    visited[next.r][current.c] = true;

                                    // Đẩy ô next vào hàng đợi
                                    q.push(next);
                                }
        }
    }
}


void process()
{
    // Khởi tạo mảng visited
    visited.resize(R, vector<bool>(C, false));

    cell start_cell;

    // Duyệt từng ô trong lưới grid
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            // Nếu ô có giá trị dương và chưa duyệt
            if (grid[r][c] > 0)
            {
                if (visited[r][c] == false)
                {
                    // thì bắt đầu tính là một vùng mới
                    region_count += 1;

                    // thực hiện bfs từ ô này
                    start_cell.r = r;
                    start_cell.c = c;
                    bfs(start_cell);
                }
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