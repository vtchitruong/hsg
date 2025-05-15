import os
import sys

input_file = os.path.join(sys.path[0], 'sums.inp')
output_file = os.path.join(sys.path[0], 'sums.out')

n = 0


def input():
    global n
    
    with open(input_file) as f:
        n = int(f.readline().strip())


def process():
    global n, S
    
    S = n * (n + 2)


def output():
    global S

    with open(output_file, 'w') as f:
        f.write(str(S))


if __name__ == '__main__':
    input()
    process()
    output()