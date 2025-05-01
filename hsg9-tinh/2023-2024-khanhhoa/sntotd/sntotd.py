import os
import sys
import math

input_file = os.path.join(sys.path[0], 'sntotd.inp')
output_file = os.path.join(sys.path[0], 'sntotd.out')

# 10^6 * 10 + 9 < 10^7 + 10
MAX = 10000010

n = 0
A = []

# Khởi tạo mảng prime để lưu trữ sàng Eratosthenes
prime = [True] * MAX

# Mảng chưa các kết quả
results = []


# Hàm tạo sàng Eratosthenes
def sieve():
    # 0 và 1 không phải nguyên tố
    prime[0] = False
    prime[1] = False

    # Duyệt các số từ 2 trở đi
    for p in range(2, int(math.sqrt(MAX)) + 1):
        # Nếu p là số nguyên tố
        if prime[p] == True:
            # thì đánh dấu False cho các bội số của p
            for i in range(p * p, MAX, p):
                prime[i] = False


# Hàm kiểm tra điều kiện 1:
def check_1(x):
    global prime

    # Kiểm tra x có phải là nguyên tố không
    return prime[x] == True


# Hàm kiểm tra điều kiện 2:
def check_2(x):
    global prime
    
    tmp = x // 10

    # Lần lượt bỏ chữ số bên phải mà vẫn còn nguyên tố
    while tmp > 0:
        if prime[tmp] == False:
            return False
        
        tmp = tmp // 10
    
    return True


# Hàm kiểm tra điều kiện 3:
def check_3(x):
    global prime
    
    # Thêm chữ số vào bên phải và số mới vẫn là nguyên tố
    for d in range(10):
        tmp = x * 10 + d

        if tmp < MAX:
            if prime[tmp] == True:
                return True

    return False


# Hàm kiểm tra số nguyên tố toàn diện
def is_comprehensive_prime(x):
    if check_1(x) == False:
        return False
    
    if check_2(x) == False:
        return False
    
    if check_3(x) == False:
        return False
    
    return True


def input_process():
    global n, A, m, results

    # Khởi tạo sàng Eratosthenes
    sieve()

    with open(input_file, 'r') as f:
        n = int(f.readline())

        # Đọc các phần tử của mảng A
        A = list(map(int, f.readline().split()))
        A.insert(0, 0)

        # Khởi tạo mảng tổng cộng dồn (prefix sum)
        # count_cp[i] lưu số lượng số nguyên tố toàn diện trong phạm vi [1..i]
        count_cp = [0] * (n + 1)

        # Duyệt mảng A
        for i in range(1, n + 1):
            # Cập nhật mảng cộng dồn
            count_cp[i] = count_cp[i - 1] + (1 if is_comprehensive_prime(A[i]) else 0)

        m = int(f.readline())

        # Khởi tạo mảng chứa kết quả
        results = [0] * m

        # Duyệt từng truy vấn [u, v]
        for i in range(m):
            # Đọc truy vấn
            u, v = map(int, f.readline().split())

            # Cập nhật kết quả của từng truy vấn dựa trên mảng tổng cộng dồn
            results[i] = count_cp[v] - count_cp[u - 1]


def output():
    global results

    with open(output_file, 'w') as f:
        for result in results:
            f.write(f'{str(result)}\n')


if __name__ == '__main__':
    input_process()
    output()