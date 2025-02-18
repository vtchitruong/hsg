import os
import sys

input_file = os.path.join(sys.path[0], 'choncam1.inp')
output_file = os.path.join(sys.path[0], 'choncam1.out')

n = 0
trays = []

# Mảng tần số f
f = [0] * 6

# Mảng continuous dùng để đánh dấu tính liên tiếp của loại cam
continuous = [False] * 6


def input_data():
    global n, trays

    with open(input_file, 'r') as f:
        n = int(f.readline())

        trays = [[0, 0] for _ in range(n)]

        for i in range(n):
            trays[i] = list(map(int, f.readline().split()))


# Hàm dùng để đánh dấu tính liên tiếp của loại cam
def mark(first, second):
    global continuous

    # Đặt tất cả phần tử trong mảng continuous đều là False
    continuous = [False] * 6

    # Đánh dấu liên tiếp
    continuous[first] = continuous[second] = True


def process():
    global n, trays, f, continuous

    # Duyệt từng khay
    for i in range(n):
        # Đọc hai loại cam trong khay i
        first = trays[i][0];
        second = trays[i][1];

        # Nếu là loại cam thứ nhất đang liên tục thì tăng tần số lên 1
        # Ngược lại, không liên tục, thì đếm lại từ đầu
        if continuous[first]:
            f[first] += 1;
        else:
            f[first] = 1;

        # Nếu là loại cam thứ hai đang liên tục thì tăng tần số lên 1
        # Ngược lại, không liên tục, thì đếm lại từ đầu
        if continuous[second]:
            f[second] += 1;
        else:
            f[second] = 1;
        
        # Đánh dấu lại tính liên tục cho từng loại cam
        mark(first, second)


def output():
    global f

    # Tìm số lượng của loại cam có tần số lớn nhất
    orange_count = max(f)

    # Tìm loại cam có tần số lớn nhất
    orange_type = f.index(orange_count)

    with open(output_file, 'w') as f_out:
        f_out.write(f'{orange_count} {orange_type}')


if __name__ == '__main__':
    input_data()
    process()
    output()
