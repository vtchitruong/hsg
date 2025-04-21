import os
import sys

input_file = os.path.join(sys.path[0], 'hoctoan1.inp')
output_file = os.path.join(sys.path[0], 'hoctoan1.out')

a = b = 0
x = y = 0


def input_data():
    global a, b

    with open(input_file, 'r') as f:
        a, b = map(int, f.readline().split())
    

# Hàm tìm ước chung lớn nhất
def gcd(u, v):
    while u != 0:
        v, u = u, v % u

    return v


def process():
    global a, b, x, y
    
    if b % a != 0:
        x = -1
        return
    else:
        p = b / a

        y1 = 0

        # tổng x1 + y1 đang xét
        current_sum = 0

        # biến min_sum lưu tổng x1 + y1 nhỏ nhất
        min_sum = float('inf')

        # Duyệt từng ước x1 của p (p = b/a)
        for x1 in range(1, int(p ** 0.5) + 1):
            # Nếu x1 là ước của p
            if p % x1 == 0:
                # thì tìm ước còn lại y1
                y1 = p / x1

                # Nếu x1 và y1 nguyên tố cùng nhau
                if gcd(x1, y1) == 1:                
                    # thì tính tổng x1 + y1
                    current_sum = x1 + y1

                    # Cập nhật tổng nhỏ nhất
                    if current_sum < min_sum:
                        min_sum = current_sum
                        x = a * x1
                        y = a * y1
                    

def output():
    global x, y

    with open(output_file, 'w') as f:
        if x == -1:
            f.write(str(-1))        
        else:
            s = x + y
            f.write(f'{int(s)}\n{int(x)} {int(y)}')


if __name__ == '__main__':
    input_data()
    process()
    output()