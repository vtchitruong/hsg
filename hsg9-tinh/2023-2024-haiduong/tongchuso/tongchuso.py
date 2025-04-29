import os
import sys

input_file = os.path.join(sys.path[0], 'tongchuso.inp')
output_file = os.path.join(sys.path[0], 'tongchuso.out')

n = 0
Sum = 0


def input():
    global n

    with open(input_file, 'r') as f:
        n = int(f.readline())


def process():
    global n, Sum

    while n > 0:
        Sum += n % 10
        n = n // 10


def output():
    global Sum

    with open(output_file, 'w') as f:
        f.write(str(Sum))


if __name__ == '__main__':
    input()
    process()
    output()
