import os
import sys

input_file = os.path.join(sys.path[0], 'tuoicay.inp')
output_file = os.path.join(sys.path[0], 'tuoicay.out')

n = k = 0
A = []
max_count = 0


def input():
    global n, k, A

    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())

        A = list(map(int, f.readline().split()))


def process():
    global n, k, A, max_count

    left = 0

    # tổng số nước đã tưới
    water = 0

    # Duyệt từng vị trí trong mảng A
    for right in range(n):
        # Cộng dồn tổng số nước đã sử dụng
        water += A[right]

        # Thu hẹp cửa sổ nếu cần
        while water > k and left <= right:
            water -= A[left]
            left += 1

        # Cập nhật số lượng cây nhiều nhất được tưới
        if water <= k:
            max_count = max(max_count, right - left + 1)


def output():
    global max_count

    with open(output_file, 'w') as f:
        f.write(str(max_count))


if __name__ == '__main__':
    input()
    process()
    output()