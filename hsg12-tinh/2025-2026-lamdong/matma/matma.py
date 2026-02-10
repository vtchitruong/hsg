import os
import sys

input_file = os.path.join(sys.path[0], "matma1.inp")
output_file = os.path.join(sys.path[0], "matma1.out")

a, n = 0, 0

result = 1

def input():
    sys.stdin = open(input_file, 'r')

    global a, n
    a, n = map(int, sys.stdin.readline().split())


def process_1():
    global a, n, result

    # Mod 10 để lấy chữ số cuối của a
    a %= 10

    # Trong khi số mũ n vẫn còn chia đôi được
    while n > 0:
        if n & 1:        
            # Nếu số mũ lẻ thì chỉ nhân thêm cơ số a vào
            result = (result * a) % 10
        
        # Ngược lại, nếu số mũ chẵn thì bình phương cơ số a lên
        a = (a * a) % 10

        # Chia đôi số mũ
        n >>= 1
    

def process_2():
    global a, n, result

    # Mod 10 để lấy chữ số cuối của a
    a %= 10

    # Ánh xạ số mũ n thành số mũ k
    k = (n - 1) % 4 + 1

    result = pow(a, k) % 10


def output():
    sys.stdout = open(output_file, 'w')
    
    global result
    print(result)


if __name__ == '__main__':
    input()
    # process_1()
    process_2()
    output()