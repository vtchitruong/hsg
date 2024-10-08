import os
import sys

input_file = os.path.join(sys.path[0], 'bnum4.inp')
output_file = os.path.join(sys.path[0], 'bnum4.out')

n = ''
prime = False
sum_digit = 0


def input_data():
    global n
    
    with open(input_file, 'r') as f:
        n = f.readline().strip()


# Hàm kiểm tra số nguyên tố
def is_prime(x):
    if x < 2:
        return False
    if x < 4:
        return True
    if x % 2 == 0 :
        return False
    if x % 3 == 0:
        return False
    for i in range(5, int(x**0.5) + 1, 6):
        if n % i == 0:
            return False
        if n % (i + 2) == 0:
            return False

    return True


def process():
    global n, prime, sum_digit

    # Duyệt từng chữ số trong chuỗi n
    # chuyển đổi và tính tổng bình phương
    sum_digit = sum((int(c) ** 2) for c in n)
    
    prime = 1 if is_prime(sum_digit) else -1


def output(prime: int, sum_digit: int):
    with open(output_file, 'w') as f:
        f.write(f'{prime}\n{sum_digit}')


if __name__ == '__main__':
    input_data()
    process()
    output(prime, sum_digit)