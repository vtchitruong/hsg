import os
import sys

input_file = os.path.join(sys.path[0], 'tangqua2.inp')
output_file = os.path.join(sys.path[0], 'tangqua2.out')

n = 0
A = []
B = []

def input_data():
    global n, A
    with open(input_file, 'r') as f:
        n = int(f.readline().strip())
        A = list(map(int, f.readline().split()))


def process():
    global n, A, B

    # Khởi tạo mảng tần số granted, dùng để đánh dấu những món quà đã phát
    granted = [0] * 1000001

    # Khởi tạo món quá có giá trị nhỏ nhất là 1
    least = 1

    # Duyệt tất cả món quà
    for a in A:

        # Đánh dấu món quà có giá trị a đã phát
        granted[a] += 1

        # Nếu món quà có giá trị least đã được phát
        # thì tăng least thêm 1
        while granted[least] == 1:
            least += 1

        # Ghi nhận least là giá trị nhỏ nhất tại món quà a đang xét
        B.append(least)


def output():
    global n, B

    with open(output_file, 'w') as f:
        f.write(' '.join(map(str, B)))


if __name__ == '__main__':
    input_data()
    process()
    output()