import os
import sys

input_file = os.path.join(sys.path[0], 'nangluong.inp')
output_file = os.path.join(sys.path[0], 'nangluong.out')

n = a = b = 0
p = 0 # số ngày luyện tập cần tìm


def input():
    global n, a, b

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))
    a = int(next(iterator))
    b = int(next(iterator))


def process():
    global n, b, b, p

    numerator = n * a
    denominator = a + b

    if numerator % denominator == 0:
        p = int(numerator / denominator)
    else:
        p = -1


def output():
    global p

    sys.stdout = open(output_file, 'w')

    print(p)


if __name__ == '__main__':
    input()
    process()
    output()