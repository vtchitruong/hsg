import os
import sys

input_file = os.path.join(sys.path[0], 'dulich.inp')
output_file = os.path.join(sys.path[0], 'dulich.out')

INF = float('inf')

n = 0
c = []

# Khai báo mảng hai chiều d gồm 2^15 hàng, 15 cột
# d[mask][u] lưu chi phí nhỏ nhất đi qua các điểm trong mask, kết thúc tại điểm u
d = []

# tổng chi phí nhỏ nhất, dùng để output
result = INF

def input():
    global n, c, d

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))

    c = [[0] * n for _ in range(n)]

    for u in range(n):
        for v in range(n):
            x = int(next(iterator))
            c[u][v] = x  


def process():
    global n, c, d, result

    # Khởi tạo mảng d gồm toàn giá trị vô cực
    d = [[INF] * n for _ in range(1 << n)]    
    
    # Khởi tạo chi phí 0 cho các điểm xuất phát
    for v in range(n):
        d[1 << v][v] = 0

    # Duyệt tất cả các trạng thái của mask
    for mask in range(1, 1 << n):
        # Duyệt từng điểm u đang đứng
        for u in range(n):
            # Kiểm tra xem u có nằm trong mask hay không
            if mask & (1 << u):
            
                # Kiểm tra xem có đường đi tới u hay không
                if d[mask][u] == INF:
                    continue

                # Duyệt điểm v chưa có trong mask, tức thử đi từ u đến v
                for v in range(n):
                    # Nếu chưa ghé thăm điểm v
                    if not mask & (1 << v):
                        # Đánh dấu v đã được ghé thăm
                        next_mask = mask | (1 << v)

                        # Tính tổng chi phí mới
                        new_cost = d[mask][u] + c[u][v]

                        # Cập nhật chi phí nhỏ hơn
                        if new_cost < d[next_mask][v]:
                            d[next_mask][v] = new_cost

    # Tìm giá trị nhỏ nhất của tất cả các trạng thái full mask, tức mask = 11...1
    full_mask = (1 << n) - 1

    for v in range(n):    
        if d[full_mask][v] < result:
            result = d[full_mask][v]


def output():
    global result
    sys.stdout = open(output_file, 'w')
    print(result)


if __name__ == '__main__':
    input()
    process()
    output()