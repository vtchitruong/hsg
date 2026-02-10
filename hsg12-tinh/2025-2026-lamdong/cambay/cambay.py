import os
import sys

input_file = os.path.join(sys.path[0], "cambay.inp")
output_file = os.path.join(sys.path[0], "cambay.out")

n, m = 0, 0
matrix = []

min_value = float('inf')
max_value = float('-inf')

result = 0


def input():
    global n, m, matrix, min_value, max_value, result

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    input_data = sys.stdin.read().split()

    iterator = iter(input_data)

    n = int(next(iterator))
    m = int(next(iterator))

    total_elements = n * m
    matrix = [0] * total_elements

    # Đọc dữ liệu và chuyển đổi luôn sang mảng một chiều
    for i in range(total_elements):
        value = int(next(iterator))
        matrix[i] = value
        
        # Tìm giá trị nhỏ nhất
        if value < min_value:
            min_value = value

        # Tìm giá trị lớn nhất
        if value > max_value:
            max_value = value
        
    
def process():
    global n, m , matrix, result

    trap_rows = [False] * n
    trap_cols = [False] * m

    for r in range(n):
        for c in range(m):
            i = r * m + c

            # Lấy ra giá trị tại hàng r, cột c
            value = matrix[i]

            if value == min_value or value == max_value:            
                # Nếu giá trị lấy ra bằng nhỏ nhất hoặc lớn nhất
                # thì đánh dấu hàng r, cột c có bẫy
                trap_rows[r] = True
                trap_cols[c] = True

    # Đếm số hàng không có bẫy
    no_trap_row_count = trap_rows.count(False)

    # Đếm số cột không có bẫy
    no_trap_col_count = trap_cols.count(False)

    result = no_trap_row_count * no_trap_col_count


def output():
    global result

    sys.stdout = open(output_file, 'w')
    print(result)


if __name__ == '__main__':
    input()
    process()
    output()