import os
import sys

input_file = os.path.join(sys.path[0], 'tuongdong.inp')
output_file = os.path.join(sys.path[0], 'tuongdong.out')

n = X = 0
pictures = []

# Số cách cần tìm
number_of_ways = 0


def input_data():
    global n, X, pictures

    with open(input_file, 'r') as f:
        n, X = map(int, f.readline().split())
        pictures = list(map(int, f.readline().split()))


def process():
    global number_of_ways

    # Sắp xếp mảng pictures theo thứ tự tăng dần
    pictures.sort()

    # Duyệt từng tranh từ 0 đến áp cuối
    for i in range(n - 1):
        # Tính giới hạn màu sắc
        limit = pictures[i] + X

        # Tìm vị trí đầu tiên mà màu sắc vượt quá giới hạn
        j = i + 1
        while j < n and pictures[j] <= limit:
            j += 1

        # Số cách chọn hai bức tranh chính là số lượng bức tranh thứ hai có thể chọn 
        number_of_ways += (j - (i + 1))


def output():
    with open(output_file, 'w') as f:
        f.write(str(number_of_ways))


if __name__ == '__main__':
    input_data()
    process()
    output()
