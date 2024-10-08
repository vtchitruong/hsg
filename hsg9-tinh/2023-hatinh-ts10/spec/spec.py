import os
import sys

input_file = os.path.join(sys.path[0], 'spec2.inp')
output_file = os.path.join(sys.path[0], 'spec2.out')

n = 0
A = []

def input_data():
    global n, A

    with open(input_file, 'r') as f:
        n = int(f.readline().strip())
        A = list(map(lambda x: 1 if int(x) > 0 else 0, f.readline().split()))


def process():
    global n, A

    # Khởi tạo hai bộ đếm dương và âm
    count_positive = 0
    count_negative = 0

    # Khởi tạo độ dài lớn nhất cho dãy âm và dương
    max_positive = 0
    max_negative = 0

    # Duyệt mảng A
    for a in A:
        # Tăng 1 cho bộ đếm tương ứng với âm hoặc dương
        # và gán 0 cho bộ đếm còn lại
        if a == 1:
            count_positive += 1
            count_negative = 0
        else:
            count_positive = 0
            count_negative += 1

        # Ghi nhận hai độ dài lớn nhất
        max_positive = max(max_positive, count_positive)
        max_negative = max(max_negative, count_negative)

    return max(max_positive, max_negative)


def output():
    result = process()

    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input_data()
    output()