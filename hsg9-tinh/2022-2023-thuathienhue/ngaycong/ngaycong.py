import os
import sys

input_file = os.path.join(sys.path[0], 'ngaycong.inp')
output_file = os.path.join(sys.path[0], 'ngaycong.out')

n = 0
days = []

total = 0
average = 0.0


def input():
    global n, days

    with open(input_file, 'r') as f:
        n = int(f.readline())

        days = list(map(int, f.readline().split()))


def process():
    global n, days, total, average

    # Sắp xếp ngày công giảm dần
    days.sort(reverse=True)
    
    # Tính tổng số ngày
    total = sum(days)

    # Tính trung bình cộng
    average = total / n


def output():
    global days, total, average

    with open(output_file, 'w') as fo:
        fo.write(' '.join(map(str, days)) + '\n')

        fo.write(f'{total} {average:.2f}')


if __name__ == '__main__':
    input()
    process()
    output()