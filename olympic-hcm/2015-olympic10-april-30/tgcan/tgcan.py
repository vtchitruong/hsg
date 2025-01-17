import os
import sys

input_file = os.path.join(sys.path[0], 'tgcan.inp')
output_file = os.path.join(sys.path[0], 'tgcan.out')

MAX = 100000
n = 0
a = []

# Mảng tần số frequency
f = [0] * (MAX + 1)

# Số tam giác cân
result = 0


def input_data():
    global MAX, n, a, f

    with open(input_file, 'r') as file:
        n = int(file.readline())

        # Mảng input a
        a = list(map(int, file.readline().split()))
        
        # Gán giá trị cho mảng tần số f
        for x in a:
            f[x] += 1


# Hàm dùng để tính tổ hợp C(x, 3) dành cho tam giác đều
def combination_3(x):
    if x < 3:
        return 0

    return x * (x - 1) * (x - 2) // 6


# Hàm dùng để tính tổ hợp C(x, 2) dành cho tam giác cân
def combination_2(x):
    if x < 2:
        return 0

    return x * (x - 1) // 2


def process():
    global n, f, result

    # Tổng tích luỹ dùng để tính nhanh tổng của f[1]..f[i]
    # prefix[i] = f[1] + f[2] + ... + f[i]
    prefix = [0] * (MAX + 1)

    for i in range(MAX + 1):
        prefix[i] += prefix[i - 1] + f[i]
    
    # Duyệt mảng tần số f
    for u in range(1, MAX + 1):
        # Tính số tam giác đều
        result += combination_3(f[u])
    
    # Duyệt mảng tần số f
    for u in range(1, MAX + 1):
        # Nếu không đủ hai cạnh để tạo thành tam giác cân thì bỏ qua
        if f[u] < 2:
            continue

        # Tính cận trên của độ dài cạnh thứ ba (cạnh v)
        upper_bound = 2 * u - 1
        if upper_bound > MAX:
            upper_bound = MAX

        # Tính số cách chọn cạnh thứ ba
        count_v = prefix[upper_bound] - f[u]

        # Tính số tam giác cân (u, u, v)
        result += (combination_2(f[u]) * count_v)


def output():
    global result

    with open(output_file, 'w') as file:
        file.write(f'{result}')


if __name__ == '__main__':
    input_data()
    process()
    output()
