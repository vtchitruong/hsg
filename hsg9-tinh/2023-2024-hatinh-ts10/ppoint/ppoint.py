import os
import sys

input_file = os.path.join(sys.path[0], 'ppoint.inp')
output_file = os.path.join(sys.path[0], 'ppoint.out')

n = 0
P = []

# độ dài nhỏ nhất cần tìm
min_len = sys.maxsize


def input():
    global n, P

    with open(input_file, 'r') as f:
        n = int(f.readline().strip())
        P = []
        for _ in range(n):
            x, m = map(int, f.readline().split())
            P.append((x, m))


def process():
    global P, min_len

    # Sắp xếp mảng P theo thứ tự toạ độ tăng dần
    P.sort(key=lambda point: point[0])

    # Khởi tạo toạ độ cuối cùng tìm thấy các màu
    last_green = -1
    last_red = -1
    last_yellow = -1

    # Duyệt mảng P
    for p in P:
        # Ghi nhận toạ độ mới khi tìm thấy màu
        if p[1] == 1:
            last_green = p[0]
        elif p[1] == 2:
            last_red = p[0]
        elif p[1] == 3:
            last_yellow = p[0]

        # Nếu đã tìm thấy đủ ba toạ độ
        # thì tính độ dài đoạn thẳng
        if last_green != -1 and last_red != -1 and last_yellow != -1:
            # thì lấy toạ độ đầu và cuối
            min_pos = min(last_green, last_red, last_yellow)
            max_pos = max(last_green, last_red, last_yellow)

            # cập nhật độ dài nhỏ nhất
            min_len = min(min_len, max_pos - min_pos)


def output():
    global min_len

    with open(output_file, 'w') as f:
        if min_len == sys.maxsize:
            f.write(-1)
        else:
            f.write(str(min_len))


if __name__ == '__main__':
    input()
    process()
    output()