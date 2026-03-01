import os
import sys
from collections import deque

input_file = os.path.join(sys.path[0], 'positive.inp')
output_file = os.path.join(sys.path[0], 'positive.out')

R, C = 0, 0
grid = []
visited = []

# 8 hướng di chuyển
directions = [
    (-1, 0),  # lên
    (0, 1),   # phải
    (1, 0),   # xuống
    (0, -1),  # trái
    (-1, 1),  # phải trên
    (1, 1),   # phải dưới 
    (1, -1),  # trái dưới   
    (-1, -1)  # trái trên
]

region_count = 0


def input():
    global R, C, grid

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    R = int(next(iterator))
    C = int(next(iterator))

    grid = [[0] * C for _ in range(R)]

    for r in range(R):
        for c in range(C):
            x = int(next(iterator))
            grid[r][c] = x


def bfs(start_r, start_c):
    global R, C, grid, visited

    # Khởi tạo hàng đợi q
    q = deque([(start_r, start_c)])
    visited[start_r][start_c] = True

    # Duyệt lưới grid theo BFS và đánh dấu đã duyệt cho tất cả ô trong cùng một vùng
    while q:
        current_r, current_c = q.popleft()        

        for dr, dc in directions:
            # Lấy giá trị của ô tiếp theo
            next_r = current_r + dr
            next_c = current_c + dc

            # Kiểm tra xem ô next có thỏa các điều kiện sau không:
            # 1. nằm trong lưới
            # 2. có giá trị dương
            # 3. chưa đánh dấu
            if 0 <= next_r < R and 0 <= next_c < C and grid[next_r][next_c] > 0 and not visited[next_r][next_c]:
                # Đánh dấu ô next
                visited[next_r][next_c] = True

                # Đẩy ô next vào hàng đợi
                q.append((next_r, next_c))


def process():
    global grid, region_count, visited
    
    # Khởi tạo mảng visited
    visited = [[False] * C for _ in range(R)]

    # Duyệt từng ô trong lưới grid
    for r in range(R):
        for c in range(C):
            if grid[r][c] > 0 and not visited[r][c]:
                # Nếu ô có giá trị dương và chưa đánh dấu thì bắt đầu tính là một vùng mới
                region_count += 1

                # thực hiện bfs từ ô này
                bfs(r, c)


def output():
    sys.stdout = open(output_file, 'w')

    print(region_count)


if __name__ == '__main__':
    input()
    process()
    output()

