import os
import sys

input_file = os.path.join(sys.path[0], 'boiba.inp')
output_file = os.path.join(sys.path[0], 'boiba.out')

n = 0
A = []

# tổng giá trị cần cộng cho các phần tử
result = 0


def input():
    global n, A

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))

    A = [0] * n

    for i in range(n):
        A[i] = int(next(iterator))


def process():
    global n, A, result

    # phần tử A[i] sau khi cộng thêm để chia hết cho 3
    new_ai = 0

    # Giá trị tích luỹ từ các phần tử trước đó dùng để cộng thêm cho phần tử tiếp theo
    cumulative = 0

    # Duyệt các phần tử từ đầu đến cuối
    for i in range(n):
        # Tính a[i] sau khi cộng thêm giá trị tích luỹ để chia hết cho 3 
        new_ai = A[i] + cumulative

        # Tính số dư khi chia cho 3
        remain = new_ai % 3

        # Tính giá trị x cần cộng thêm để chia hết cho 3
        x = 0
        if remain != 0:
            x = 3 - remain

        # x > 0 nghĩa là cần phải cộng thêm x cho phần tử tiếp theo
        if x > 0:
            # Cập nhật tổng giá trị cần cộng cho phần tử, bao gồm a[i] và tất cả phần tử sau a[i]
            result += x * (n - i)

            # Cập nhật giá trị tích luỹ nhằm cộng cho phần tử tiếp theo ở vòng lặp kế tiếp
            cumulative += x


def output():
    sys.stdout = open(output_file, 'w')
    
    print(result)


if __name__ == '__main__':
    input()
    process()
    output()