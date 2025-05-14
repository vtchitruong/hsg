import os
import sys

input_file = os.path.join(sys.path[0], 'duongthang1.inp')
output_file = os.path.join(sys.path[0], 'duongthang1.out')

n = 0

# mảng lưu hệ số góc a của các đường thẳng
A = []

# số cặp đường thẳng song song
parallel = 0


def input():
    global n, A

    with open(input_file, 'r') as f:
        n = int(f.readline())

        A = [0] * n

        for i in range(n):
            A[i], b = map(int, f.readline().split())


def process():
    global n, A, parallel

    # Sắp xếp lại các hệ số góc a theo thứ tự tăng dần
    A.sort()

    # biến tạm dùng để lưu số lượng đường thẳng có cùng hệ số góc a
    tmp_count = 1

    # Duyệt từng hệ số góc từ vị trí 1 trở đi
    for i in range(1, n):
        # Nếu hệ số góc vẫn như cũ
        if A[i] == A[i - 1]:
            # thì tăng số đường thẳng có cùng hệ số góc thêm 1
            tmp_count += 1
        else:
            # Nếu có nhiều hơn 1 đường thẳng có cùng hệ số góc a
            if tmp_count > 1:
                # thì tính số cặp song song
                parallel += tmp_count * (tmp_count - 1) // 2

                # khởi tạo lại tmp_count để đếm lại cho hệ số góc mới
                tmp_count = 1

    #  Tính cho nhóm hệ số góc cuối cùng
    if tmp_count > 1:
        parallel += tmp_count * (tmp_count - 1) // 2


def output():
    global parallel

    with open(output_file, 'w') as f:
        f.write(str(parallel))


if __name__ == '__main__':
    input()
    process()
    output()