import os
import sys

input_file = os.path.join(sys.path[0], 'rutvan.inp')
output_file = os.path.join(sys.path[0], 'rutvan.out')

a, b, n, m = 0, 0, 0, 0

# Mảng lưu vị trí của các hoành độ (thanh dọc)
Xs = []

# Mảng lưu vị trí của các tung độ (thanh ngang)
Ys = []

# Mảng lengths dùng để lưu độ dài của các đoạn được cắt từ các thanh dọc lẫn thanh ngang
lengths = []

# Tổng độ dài cần tìm
total_length = 0


def input_data():
    global a, b, n, m, Xs, Ys, lengths, total_length

    with open(input_file, 'r') as f:
        a, b, n, m = map(int, f.readline().split())

        # Đọc các hoành độ (thanh dọc)
        # Nạp hoành độ đầu tiên là 0
        Xs.append(0)

        # Nạp các hoành độ của các thanh dọc
        for _ in range(n):
            Xs.append(int(f.readline()))
        
        # Nạp hoành độ cuối cùng là a
        Xs.append(a)

        # Đọc các tung độ (thanh ngang)
        # Nạp tung độ đầu tiên là 0
        Ys.append(0)

        # Nạp các tung độ của các thanh ngang
        for _ in range(m):
            Ys.append(int(f.readline()))

        # Nạp tung độ cuối cùng là b
        Ys.append(b)


def process():
    global a, b, n, m, Xs, Ys, lengths, total_length

    # Duyệt từng vị trí của các hoành độ (thanh dọc)
    for i in range(1, len(Xs)):
        # Tính độ dài của một đoạn được cắt
        l = Xs[i] - Xs[i - 1]

        # Thêm độ dài vào mảng lengths
        # Số lần thêm phải bằng với số lượng thanh ngang
        for j in range(m):
            lengths.append(l)

    # Duyệt từng vị trí của các tung độ (thanh ngang)
    for i in range(1, len(Ys)):
        # Tính độ dài của một đoạn được cắt
        l = Ys[i] - Ys[i - 1]

        # Thêm độ dài vào mảng lengths
        # Số lần thêm phải bằng với số lượng thanh dọc
        for j in range(n):
            lengths.append(l)
   
    # Sắp xếp mảng lengths tăng dần
    lengths.sort()

    # Tính số vùng ban đầu
    region_count = (n + 1) * (m + 1)

    # Tính tổng độ dài của các đoạn được cắt
    # Chỉ lấy số lượng đoạn bằng số vùng trừ đi 1
    total_length = sum(lengths[0:region_count - 1])


def output():
    global total_length

    with open(output_file, 'w') as f:
        f.write(f'{total_length}')


if __name__ == '__main__':
    input_data()
    process()
    output()
