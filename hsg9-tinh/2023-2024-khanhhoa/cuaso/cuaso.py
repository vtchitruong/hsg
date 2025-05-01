import os
import sys

input_file = os.path.join(sys.path[0], 'cuaso.inp')
output_file = os.path.join(sys.path[0], 'cuaso.out')

MAX = 1000000

n = 0

# mảng tần số lưu số lần xuất hiện của một độ dài a[i]
f = [0] * (MAX + 1)

# chu vi lớn nhất
max_perimeter = -1


def input():
    global MAX, n, f

    with open(input_file, 'r') as file:
        n = int(file.readline())

        A = map(int, file.readline().split())

    # Cập nhật số lần xuất hiện của từng độ dài
    for a in A:
        f[a] += 1


def process():
    global f, max_perimeter

    # mảng lưu các độ dài ứng viên
    candidates = []

    # Duyệt mảng tần số f
    for length in range(MAX + 1):
        # Nếu độ dài có hơn 2 que thì nạp độ dài này vào mảng ứng viên
        if f[length] >= 2:
            candidates.append(length)

        # Nếu độ dài có hơn 4 que thì nạp độ dài này vào mảng ứng viên lần nữa
        if f[length] >= 4:
            candidates.append(length)

    # Nếu mỗi độ dài ứng viên có đủ 2 loại trở lên
    if len(candidates) > 1:
        # thì sắp xếp các độ dài giảm dần
        candidates.sort(reverse=True)

        # Tính chu vi lớn nhất
        max_perimeter = 2 * (candidates[0] + candidates[1])


def output():
    global max_perimeter

    with open(output_file, 'w') as file:
        file.write(str(max_perimeter))


if __name__ == '__main__':
    input()
    process()
    output()