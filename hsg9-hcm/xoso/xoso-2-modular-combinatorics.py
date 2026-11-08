import os
import sys

input_file = os.path.join(sys.path[0], 'xoso.inp')
output_file = os.path.join(sys.path[0], 'xoso.out')

M = 10**9 + 7

n = k = 0
a = []
s = 0

f = []          # giai thừa (factorial)
inverse_f = []  # nghịch đảo giai thừa


# Hàm tính lũy thừa modular (a^b mod m) bằng phương pháp binary exponentiation
def power(base, exp):
    result = 1

    base %= M

    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % M

        base = (base * base) % M
        exp //= 2

    return result


# Hàm tính nghịch đảo giai thừa modular theo định lý Fermat nhỏ
def modular_inverse(x):
    return power(x, M - 2)


# Hàm tiền tính toán các giá trị giai thừa
def init_factorial():
    global f, inverse_f

    # Khởi tạo mảng giai thừa và mảng nghịch đảo giai thừa
    f = [1] * (n + 1)
    inverse_f = [1] * (n + 1)

    # Tính giai thừa từ 1! đến n!
    for i in range(1, n + 1):
        f[i] = (f[i - 1] * i) % M

    # Tính nghịch đảo modular của n!
    inverse_f[n] = modular_inverse(f[n])

    # Tính nghịch đảo modular từ (n - 1)! ngược về 0!
    for i in range(n - 1, -1, -1):
        inverse_f[i] = (inverse_f[i + 1] * (i + 1)) % M


# Hàm tính tổ hợp n chập k
def combinations(n, k):
    global f, inverse_f

    if k < 0 or k > n:
        return 0

    numerator = f[n]
    denominator = (inverse_f[k] * inverse_f[n - k]) % M

    return (numerator * denominator) % M


def input():
    global n, k, a

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))
    k = int(next(iterator))

    a = [0] * n

    for i in range(n):
        a[i] = int(next(iterator))


def process():
    global s

    # Sắp xếp tăng dần giá trị của các phiếu
    a.sort()

    # Tiền tính toán
    init_factorial()

    # Tính tổng điểm thưởng s bằng cách tính tổng đóng góp của các phiếu từ phiếu k - 1 cho đến phiếu cuối cùng
    for i in range(k - 1, n):
        # Tính số cách chọn k - 1 phiếu đứng liền trước phiếu A[i]
        number_of_combinations = combinations(i, k - 1)

        # Tính tổng đóng góp của phiếu A[i]
        contribution = (a[i] * number_of_combinations) % M

        # Cộng dồn đóng góp của phiếu A[i] vào tổng điểm thưởng s
        s = (s + contribution) % M


def output():
    global s

    sys.stdout = open(output_file, 'w')

    print(s)


if __name__ == '__main__':
    input()
    process()
    output()