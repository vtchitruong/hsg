import os
import sys
import math

input_file = os.path.join(sys.path[0], 'snt.inp')
output_file = os.path.join(sys.path[0], 'snt.out')

MAX = 10000000

n = l = r = 0

# Khởi tạo sàng với toàn bộ phần tử đều là 1 (true)
E = [1] * (MAX + 1)

# prime_count[i] lưu số lượng số nguyên tố từ 1 đến i
prime_count = [0] * (MAX + 1)


# Hàm thực hiện sàng nguyên tố Eratosthenes
def sieve():
    global MAX, E

    # 0 và 1 không phải số nguyên tố
    E[0] = 0
    E[1] = 0

    # Duyệt từng số p trong phạm vi [2..sqrt(MAX)]
    for p in range(2, int(math.sqrt(MAX)) + 1):
        # Nếu p là số nguyên tố:
        if E[p] == 1:
            # thì đánh dấu 0 cho các bội của p, bắt đầu từ p * p
            for i in range(p * p, MAX + 1, p):
                E[i] = 0


# Hàm tính mảng cộng dồn (prefix sum)
def prefix_sum():
    global E, prime_count

    for i in range(1, MAX + 1):
        prime_count[i] = prime_count[i - 1] + E[i]


def process():
    global MAX, n, l, r, E, prime_count

    # Khởi tạo sàng nguyên tố E
    sieve()

    # Khởi tạo mảng cộng dồn prime_count
    prefix_sum()

    with open(input_file, 'r') as fi, open(output_file, 'w') as fo:
        n = int(fi.readline())

        # Vừa đọc input vừa xuất kết quả
        for q in range(n):
            l, r = map(int, fi.readline().split())

            # Dựa vào prefix sum, in ra số lượng số nguyên tố trong phạm vi [l, r]
            result = prime_count[r] - prime_count[l - 1]
            fo.write(str(result) + '\n')


if __name__ == '__main__':
    process()