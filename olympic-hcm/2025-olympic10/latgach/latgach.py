import os
import sys

input_file = os.path.join(sys.path[0], 'latgach.inp')
output_file = os.path.join(sys.path[0], 'latgach.out')

m = n = t = 0

# độ rộng tối đa cần tìm
result = 0


def input_data():
    global m, n, t

    with open(input_file, 'r') as f:
        m, n, t = map(int, f.readline().split())


def check(weight):
    if weight == 0:
        return True

    global m, n, t

    # Trường hợp phần không lát gạch không tồn tại
    if 2 * weight >= m or 2 * weight >= n:
        return False

    # Tính số gạch cần lát
    tiles = (2 * weight) * (m + n - 2 * weight)

    return tiles <= t


def process():
    global result

    low = 0
    high = min(m, n) // 2 + 1

    while low <= high:    
        mid = low + (high - low) // 2

        if check(mid):
            result = mid

            # Tiếp tục tìm kiếm phạm vi bên phải nhằm tìm ra giá trị mid (weight) lớn nhất
            low = mid + 1
        else:
            high = mid - 1


def output():
    global result

    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input_data()
    process()
    output()