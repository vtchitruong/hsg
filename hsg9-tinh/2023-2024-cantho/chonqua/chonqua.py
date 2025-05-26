import os
import sys

input_file = os.path.join(sys.path[0], 'chonqua.inp')
output_file = os.path.join(sys.path[0], 'chonqua.out')

n = k = 0
A = []
Sum = 0


def input():
    global n, k, A

    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())

        A = list(map(int, f.readline().split()))


def process():
    global n, k, A, Sum

    # Sắp xếp mảng A theo thứ tự giảm dần
    A.sort(reverse=True)

    # Tính tổng k phần tử đầu
    Sum = sum(A[:k])


def output():
    global Sum

    with open(output_file, 'w') as f:
        f.write(str(Sum))


if __name__ == '__main__':
    input()
    process()
    output()