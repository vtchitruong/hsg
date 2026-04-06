import os
import sys

input_file = os.path.join(sys.path[0], 'tuoicay.inp')
output_file = os.path.join(sys.path[0], 'tuoicay.out')

n = k = 0
A = []
max_count = 0


def input():
    global n, k, A

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))

    k = int(next(iterator))

    A = [0] * n

    for i in range(n):
        A[i] = int(next(iterator))


def process():
    global max_count

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
    sys.stdout = open(output_file, 'w')

    print(max_count)


if __name__ == '__main__':
    input()
    process()
    output()