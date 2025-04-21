import os
import sys

input_file = os.path.join(sys.path[0], 'nangluong.inp')
output_file = os.path.join(sys.path[0], 'nangluong.out')

n = a = b = 0
p = 0 # số ngày luyện tập cần tìm


def input_data():
    global n, a, b

    with open(input_file, 'r') as f:
        n = int(f.readline())
        a = int(f.readline())
        b = int(f.readline())


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

    with open(output_file, 'w') as f:
        f.write(str(p))


if __name__ == '__main__':
    input_data()
    process()
    output()


