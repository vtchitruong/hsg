import os
import sys

input_file = os.path.join(sys.path[0], 'bangso.inp')
output_file = os.path.join(sys.path[0], 'bangso.out')

n = k = 0
count = 0


def input():
    global n, k

    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())


def process():
    global n, k, count

    # Duyệt từng chỉ số hàng trong đoạn [1..n]
    for i in range(1, n):
        # Nếu k không chia hết cho i thì không
        if k % i != 0:
            continue

        # Tính giá trị cột j
        j = k // i

        # Kiểm tra xem j có nằm trong phạm vi của bảng không (1 <= j <= n)
        if j <= n:
            count += 1


def output():
    global count

    with open(output_file, "w") as f:
        f.write(str(count))


if __name__ == '__main__':
    input()
    process()
    output()