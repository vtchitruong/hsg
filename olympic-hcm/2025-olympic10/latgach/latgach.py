import os
import sys

input_file = os.path.join(sys.path[0], 'latgach1.inp')
output_file = os.path.join(sys.path[0], 'latgach1.out')

m = n = t = 0

# độ rộng tối đa cần tìm
result = 0


def input():
    global m, n, t

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    m = int(next(iterator))
    n = int(next(iterator))
    t = int(next(iterator))


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

    sys.stdout = open(output_file, 'w')
    
    print(result)


if __name__ == '__main__':
    input()
    process()
    output()