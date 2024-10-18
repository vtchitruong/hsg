import os
import sys

input_file = os.path.join(sys.path[0], 'bieuthucnt.inp')
output_file = os.path.join(sys.path[0], 'bieuthucnt.out')

n = 0
S = []

def input():
    global n
    with open(input_file, 'r') as f:
        n = int(f.readline().strip())


# Hàm tạo sàng nguyên tố Eratosthenes
def sieve():
    global n, S

    # Giả sử tất cả đều là số nguyên tố
    S = [1] * (3 * n + 1)

    # 0 và 1 không phải nguyên tố
    S[0] = S[1] = 0

    # Duyệt từ 2 đến 3n
    i = 2
    while i * i < 3 * n + 1:
        # Nếu i là nguyên tố
        if S[i] == 1:
            # thì các bội j của i đang xét không còn nguyên tố nữa
            for j in range(i * i, 3 * n + 1, i):
                S[j] = 0
        i += 1


def process():
    global n, S

    sieve()
    
    cnt = 0

    # Duyệt tất cả x và y
    for x in range(1, n + 1):
        for y in range(1, n + 1):
            p = x + 2 * y
            if S[p] == 1:
                cnt += 1

    return cnt


def output():
    result = process()
    
    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input()
    output()
