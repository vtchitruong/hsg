import os
import sys

input_file = os.path.join(sys.path[0], 'robot.inp')
output_file = os.path.join(sys.path[0], 'robot.out')

m = n = 0

# đường đi của robot 1 và robot 2
path_1 = path_2 = ''

# mảng lưu các ô mà robot 1 và robot 2 đã đi qua
visited_1 = []
visited_2 = []

# số ô mà cả hai robot cùng đi qua
result = 0


def input_data():
    global m, n, path_1, path_2

    with open(input_file, 'r') as f:
        m, n = map(int, f.readline().split())
        path_1 = f.readline().strip()
        path_2 = f.readline().strip()


def process():
    global m, n, path_1, path_2, visited_1, visited_2, result

    # Khởi tạo mảng visited_1 lưu các ô mà robot 1 đã đi qua
    visited_1 = [[False for _ in range(n)] for _ in range(m)]

    # Toạ độ hiện hành của robot 1
    r1 = 0
    c1 = 0
    visited_1[r1][c1] = True

    # Khởi tạo mảng visited_2 lưu các ô mà robot 2 đã đi qua
    visited_2 = [[False for _ in range(n)] for _ in range(m)]

    # Toạ độ hiện hành của robot 2
    r2 = m - 1
    c2 = n - 1
    visited_2[r2][c2] = True
    
    # Duyệt từng ký tự trong chuỗi hành trình
    for i in range(len(path_1)):        
        # Cập nhật toạ độ mới của robot 1
        if path_1[i] == 'D':
            r1 += 1
        else:
            c1 += 1

        # Đánh dấu ô mà robot 1 đã đi qua
        if r1 > -1:
            if r1 < m:
                if c1 > -1:
                    if c1 < n:
                        visited_1[r1][c1] = True

        # Cập nhật toạ độ mới của robot 2
        if path_2[i] == 'U':
            r2 -= 1
        else:
            c2 -= 1

        # Đánh dấu ô mà robot 2 đã đi qua
        if r2 > -1:
            if r2 < m:
                if c2 > -1:
                    if c2 < n:
                        visited_2[r2][c2] = True
    
    # Đếm số ô mà cả hai robot cùng đi qua
    for r in range(m):
        for c in range(n):
            if visited_1[r][c] and visited_2[r][c]:
                result += 1
    

def output():
    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input_data()
    process()
    output()