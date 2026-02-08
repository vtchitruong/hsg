import os
import sys
import math

input_file = os.path.join(sys.path[0], 'snt.inp')
output_file = os.path.join(sys.path[0], 'snt.out')

MAX = 10000000

n = l = r = 0

# Khởi tạo sàng eratosthenes với toàn bộ phần tử đều là 1 (true)
e = [1] * (MAX + 1)

# prime_count[i] lưu số lượng số nguyên tố từ 1 đến i
prime_count = [0] * (MAX + 1)


# Hàm khởi tạo sàng nguyên tố eratosthenes
def sieve():
    global MAX, e

    # 0 và 1 không phải số nguyên tố
    e[0] = 0
    e[1] = 0

    # Duyệt từng số p trong phạm vi [2..sqrt(MAX)]
    for p in range(2, int(math.sqrt(MAX)) + 1):
        if e[p] == 1:
            # Nếu p là số nguyên tố thì đánh dấu 0 cho các bội của p, bắt đầu từ p * p
            for i in range(p * p, MAX + 1, p):
                e[i] = 0


# Hàm tính mảng cộng dồn (prefix sum)
def prefix_sum():
    global e, prime_count

    for i in range(1, MAX + 1):
        prime_count[i] = prime_count[i - 1] + e[i]


# Hàm vừa đọc input vừa xuất kết quả
def process():
    global MAX, n, l, r, e, prime_count

    # Khởi tạo sàng nguyên tố e
    sieve()

    # Tính mảng cộng dồn prime_count
    prefix_sum()

    sys.stdin = open(input_file, 'r')
    sys.stdout = open(output_file, 'w')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))

    for _ in range(n):
        l = int(next(iterator))
        r = int(next(iterator))

        # Dựa vào prefix sum, in ra số lượng số nguyên tố trong phạm vi [l, r]
        result = prime_count[r] - prime_count[l - 1]
        print(result)


if __name__ == '__main__':
    process()