import os
import sys

input_file = os.path.join(sys.path[0], 'tamgiac.inp')
output_file = os.path.join(sys.path[0], 'tamgiac.out')


class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

A, B, C, M = point(0, 0), point(0, 0), point(0, 0), point(0, 0)

# Số epsilon
eps = 1e-9


def input_data():
    global A, B, C, M
    with open(input_file, 'r') as f:
        A.x, A.y = map(float, f.readline().strip().split())
        B.x, B.y = map(float, f.readline().strip().split())
        C.x, C.y = map(float, f.readline().strip().split())
        M.x, M.y = map(float, f.readline().strip().split())


# Hàm dùng để tính diện tích tam giác
def area(a, b, c):
    return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2)


def process():
    global A, B, C, M

    # Tính diện tích tam giác ABC
    abc = area(A, B, C)

    # Tính diện tích ba tam giác ABM, ACM, BCM
    abm = area(A, B, M)
    acm = area(A, C, M)
    bcm = area(B, C, M)

    # Nếu tổng diện tích ba tam giác con bằng diện tích tam giác ABC thì M thuộc tam giác ABC
    if abs(abc - abm - acm - bcm) < eps:
        result = 1
    else:
        result = 0

    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input_data()
    process()