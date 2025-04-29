import os
import sys

input_file = os.path.join(sys.path[0], 'banhtrungthu.inp')
output_file = os.path.join(sys.path[0], 'banhtrungthu.out')

m = n = 0
result = 0


def input():
    global m, n

    with open(input_file, 'r') as f:
        m = int(f.readline())
        n = int(f.readline())


def process():
    global n, m, result

    # Số lượng giá trị k chia hết cho m mà không vượt quá n
    count_n_m = n // m

    # Số lượng giá trị k + 1 chia hết cho m mà không vượt quá n
    count_n_1_m = (n + 1) // m

    # Số lượng cần tìm
    result = count_n_m + count_n_1_m


def output():
    global result

    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input()
    process()
    output()
