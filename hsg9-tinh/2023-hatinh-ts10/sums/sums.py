import os
import sys

input_file = os.path.join(sys.path[0], 'sums2.inp')
output_file = os.path.join(sys.path[0], 'sums2.out')

def input_data():
    with open(input_file) as f:
        n = int(f.readline().strip())
    return n


def process(n):
    S = n * (n + 2)
    return S


def output(S):
    with open(output_file, 'w') as f:
        f.write(str(S))


if __name__ == '__main__':
    n = input_data()
    S = process(n)
    output(S)