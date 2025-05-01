import os
import sys

input_file = os.path.join(sys.path[0], 'demgao.inp')
output_file = os.path.join(sys.path[0], 'demgao.out')

a = b = k = 0
count_multiples = 0


def input():
    global a, b, k

    with open(input_file, 'r') as f:
        a, b, k = map(int, f.readline().split())


def process():
    global a, b, k, count_multiples

    # Số lượng bội của k trong phạm vi [1..b]
    count_b_k = b // k

    # Số lượng bội của k trong phạm vi [1..a - 1]
    count_a_1_k = (a - 1) // k 

    # Số lượng bội của k trong phạm vi [a..b]
    count_multiples = count_b_k - count_a_1_k 


def output():
    global count_multiples

    with open(output_file, 'w') as f:
        f.write(str(count_multiples))


if __name__ == '__main__':
    input()
    process()
    output()