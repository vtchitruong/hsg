import os
import sys

input_file = os.path.join(sys.path[0], 'tamgiaccan.inp')
output_file = os.path.join(sys.path[0], 'tamgiaccan.out')

a = b = 0


def input():
    global a, b

    with open(input_file, 'r') as f:
        a = int(f.readline())
        b = int(f.readline())


def process():
    global c
    c = max(a, b)


def output():
    global c
    
    with open(output_file, 'w') as f:
        f.write(str(c))


if __name__ == '__main__':
    input()
    process()
    output()