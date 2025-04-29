import os
import sys

input_file = os.path.join(sys.path[0], 'phuongtrinh.inp')
output_file = os.path.join(sys.path[0], 'phuongtrinh.out')

n = 0
count_x = 0


def input():
    global n

    with open(input_file, 'r') as f:
        n = int(f.readline())


def sum_digits(a):
    Sum = 0
    while a > 0:
        Sum += a % 10
        a = a // 10
    
    return Sum


def process():
    global n, count_x

    # Khởi tạo giá trị xuất phát của nghiệm x
    start_x = max(1, n - 81)

    # Duyệt từng giá trị x từ start_x đến n 
    for x in range(start_x, n):
        if x + sum_digits(x) == n:
            count_x += 1


def output():
    global count_x

    with open(output_file, 'w') as f:
        f.write(str(count_x))


if __name__ == '__main__':
    input()
    process()
    output()