import os
import sys

input_file = os.path.join(sys.path[0], 'gacho.inp')
output_file = os.path.join(sys.path[0], 'gacho.out')

n = result = 0


def input():
    global n

    with open(input_file, 'r') as f:
        n = int(f.readline())


def process():
    global n, result

    k = (n - 1) // 2
    
    result = k * (n - k - 1)


def output():
    global result

    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input()
    process()
    output()