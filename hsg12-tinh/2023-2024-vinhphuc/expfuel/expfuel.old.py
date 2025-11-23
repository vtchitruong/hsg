import os
import sys

input_file = os.path.join(sys.path[0], 'expfuel.inp')
output_file = os.path.join(sys.path[0], 'expfuel.out')

n, m, c = 0, 0, 0
A = []
D = []
result = []


def input_data():
    global n, m, c, A, D

    with open(input_file, 'r') as f:
        n, m, c = map(int, f.readline().split())

        for _ in range(n):
            position, fuel = map(int, f.readline().split())
            A.append((position, fuel))
        
        for _ in range(m):
            dj = int(f.readline())
            D.append(dj)


# Hàm tính tổng nhiên liệu bao gồm đường bay và đường bộ
def fuel(flying_fuel, ai, dj):
    return flying_fuel + c * abs(ai - dj)


def process():
    global A, D, result

    # Duyệt điểm thám hiểm dj của các đội
    for dj in D:
        min_fuel = float('inf')

        # Duyệt các điểm tập kết a_i của đội dj đang xét
        for position, flying_fuel in A:
            min_fuel = min(min_fuel, fuel(flying_fuel, position, dj))

        result.append(min_fuel)


def output():
    global result
    with open(output_file, 'w') as f:
        f.write('\n'.join(map(str, result)))


if __name__ == '__main__':
    input_data()
    process()
    output()