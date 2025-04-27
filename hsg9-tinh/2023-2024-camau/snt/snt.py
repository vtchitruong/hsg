import os
import sys
import math

input_file = os.path.join(sys.path[0], 'snt.inp')
output_file = os.path.join(sys.path[0], 'snt.out')

MAX = 10000000

n = l = r = 0

# Khởi tạo sàng với toàn bộ phần tử đều là 1 (true)
prime = [1] * (MAX + 1)

# prime_count[i] lưu số lượng số nguyên tố từ 1 đến i
prime_count = [0] * (MAX + 1)


# Hàm thực hiện sàng nguyên tố Eratosthenes
def sieve():
    global MAX, prime

    # 0 và 1 không phải số nguyên tố
    prime[0] = 0
    prime[1] = 0

    # Duyệt từng số p trong phạm vi [2..sqrt(MAX)]
    for p in range(2, int(math.sqrt(MAX)) + 1):
        # Nếu p là số nguyên tố:
        if prime[p] == 1:
            # thì đánh dấu 0 cho các bội của p, bắt đầu từ p * p
            for i in range(p * p, MAX + 1, p):
                prime[i] = 0


def process():
    global MAX, n, l, r, prime, prime_count

    # Thực hiện sàng nguyên tố
    sieve()

    # Thực hiện tính prefix sum (tổng cộng dồn)
    for i in range(1, MAX + 1):
        prime_count[i] = prime_count[i - 1] + prime[i]

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