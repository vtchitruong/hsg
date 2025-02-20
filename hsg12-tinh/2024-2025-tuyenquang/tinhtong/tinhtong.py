import os
import sys

input_file = os.path.join(sys.path[0], 'tinhtong.inp')
output_file = os.path.join(sys.path[0], 'tinhtong.out')

n = 0
A = []

# Tổng cần tìm
result = 0


def input_data():
    global n, A

    with open(input_file, 'r') as file:
        n = int(file.readline())
        A = list(map(int, file.readline().split()))


def process():
    global n, A, result

    result = 0

    # Duyệt từng phần tử trong mảng A
    for a in A:
        # Kiểm tra thoả điều kiện và cộng dồn
        if a % 10 > a // 10 % 10:
            result += a


def output():
    global result

    with open(output_file, 'w') as file:
        file.write(str(result))


if __name__ == '__main__':
    input_data()
    process()
    output()