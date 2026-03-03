import os
import sys

input_file = os.path.join(sys.path[0], 'doxingau.inp')
output_file = os.path.join(sys.path[0], 'doxingau.out')

s1 = s2 = s3 = 0

# mảng tần số lưu số lần xuất hiện của mỗi tổng
counter = 0
result = 0


def input():
    global s1, s2, s3

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    s1 = int(next(iterator))
    s2 = int(next(iterator))
    s3 = int(next(iterator))


def process():
    global result

    # Khởi tạo mảng tần số
    counter = [0] * (s1 + s2 + s3 + 1)

    # Duyệt từng mặt của từng xí ngầu
    for i in range(1, s1 + 1):
        for j in range(1, s2 + 1):
            for k in range(1, s3 + 1):
                # Tăng số lần xuất hiện của tổng thêm 1
                counter[i + j + k] += 1

    # Lấy chỉ số của phần tử lớn nhất, cũng chính là tổng của 3 xí ngầu
    result = counter.index(max(counter))


def output():
    sys.stdout = open(output_file, 'w')

    print(result)


if __name__ == '__main__':
    input()
    process()
    output()