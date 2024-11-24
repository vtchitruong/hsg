import os
import sys

input_file = os.path.join(sys.path[0], 'phomai.inp')
output_file = os.path.join(sys.path[0], 'phomai.out')

a = b = 0
result = 0

class factors:
    def __init__(self, x=0, y=0, z=0, remaining=0):
        self.x = x # số mũ của 2
        self.y = y # số mũ của 3
        self.z = z # số mũ của 5
        self.remaining = remaining # phần dư sau khi phân tích luỹ thừa   


def input_data():
    global a, b
    with open(input_file, 'r') as f:
        a, b = map(int, f.readline().split())


# Hàm dùng để phân tích số n thành thừa số nguyên tố 2, 3 và 5
def factorize(n):
    f = factors()

    # Chia 2 nhiều lần để lấy số mũ của 2
    while n % 2 == 0:
        n /= 2
        f.x += 1


    # Chia 3 nhiều lần để lấy số mũ của 3
    while n % 3 == 0:
        n /= 3
        f.y += 1

    # Chia 5 nhiều lần để lấy số mũ của 5
    while n % 5 == 0:
        n /= 5
        f.z += 1

    # Phần dư còn lại của n
    f.remaining = n

    return f


def process():
    global a, b, result
    
    # Phân tích a và b
    fa = factorize(a)
    fb = factorize(b)

    # Nếu phần dư không bằng nhau thì có nghĩa là không có cách chia
    if fa.remaining != fb.remaining:
        result = -1
        return
    
    # Ngược lại, nếu phần dư bằng nhau thì tính tổng các chênh lệch giữa các số mũ
    result = abs(fa.x - fb.x) + abs(fa.y - fb.y) + abs(fa.z - fb.z)
    

def output():
    global result
    with open(output_file, 'w') as f:
        f.write(f'{result}')


if __name__ == '__main__':
    input_data()
    process()
    output()