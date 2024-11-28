import os
import sys
from collections import deque

input_file = os.path.join(sys.path[0], 'positive.inp')
output_file = os.path.join(sys.path[0], 'positive.out')

class cell:
    def __init__(self, r, c):
        self.r = r
        self.c = c

R, C = 0, 0
grid = []
visited = []

# 8 hướng di chuyển
directions = [
    cell(-1, 0), # lên
    cell(0, 1), # phải
    cell(1, 0), # xuống
    cell(0, -1), # trái
    cell(-1, 1), # phải trên
    cell(1, 1), # phải dưới 
    cell(1, -1), # trái dưới   
    cell(-1, -1) # trái trên
    ]

region_count = 0


def input_data():
    global R, C, grid
    
    with open(input_file) as f:
        R, C = map(int, f.readline().split())
        grid = [list(map(int, f.readline().split())) for _ in range(R)]


def bfs(start):
    global R, C, grid, visited

    # Khởi tạo hàng đợi q
    q = deque([start])

    # Duyệt lưới grid theo BFS và đánh dấu đã duyệt cho tất cả ô trong cùng một vùng
    while q:
        current = q.popleft()
        visited[current.r][current.c] = True

        for direction in directions:
            # Lấy giá trị của ô next
            next_r = current.r + direction.r
            next_c = current.c + direction.c

            # Kiểm tra xem ô next có thoả các điều kiện sau không:
            # 1. nằm trong lưới
            # 2. có giá trị dương
            # 3. chưa duyệt
            if next_r > -1:
                if next_r < R:
                    if next_c > -1:
                        if next_c < C:
                            if grid[next_r][next_c] > 0:
                                if visited[next_r][next_c] == False:
                                    # Đánh dấu ô next đã duyệt
                                    visited[next_r][next_c] = True

                                    # Đẩy ô next vào hàng đợi
                                    q.append(cell(next_r, next_c))


def process():
    global grid, region_count, visited
    
    # Khởi tạo mảng visited
    visited = [[False] * C for _ in range(R)]

    # Duyệt từng ô trong lưới grid
    for r in range(R):
        for c in range(C):
            # Nếu ô có giá trị dương và chưa duyệt
            if grid[r][c] > 0:
                if visited[r][c] == False:
                    # thì bắt đầu tính là một vùng mới
                    region_count += 1

                    # thực hiện bfs từ ô này
                    bfs(cell(r, c))


def output():
    global region_count

    with open(output_file, "w") as f:
        f.write(f'{region_count}')


if __name__ == '__main__':
    input_data()
    process()
    output()

