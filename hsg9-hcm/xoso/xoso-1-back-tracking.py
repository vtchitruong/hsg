import os
import sys

input_file = os.path.join(sys.path[0], 'xoso.inp')
output_file = os.path.join(sys.path[0], 'xoso.out')

M = 10**9 + 7

n = k = 0
a = []
s = 0


def input():
    global n, k, a

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))
    k = int(next(iterator))

    a = [0] * n

    for i in range(n):
        a[i] = int(next(iterator))


# Hàm phát sinh các bộ gồm k phiếu bằng phương pháp back tracking
# Đồng thời tính tổng điểm thưởng s với mỗi bộ k phiếu chọn được
def generate(k_choice, next):
    global s

    # Trường hợp cơ sở: nếu một bộ đã có đủ k phiếu thì nạp vào choices
    if len(k_choice) == k:
        # Tính phiếu có giá trị lớn nhất trong bộ gồm k phiếu
        max_value = max(k_choice)

        # Cộng dồn vào tổng điểm thưởng s
        s = (s + max_value) % M

        return

    # Phân nhánh: chọn phiếu tiếp theo bằng next
    for i in range(next, n):
        k_choice.append(a[i])
        generate(k_choice, i + 1)

        # Back tracking
        k_choice.pop()


def process():
    generate([], 0)
    

def output():
    sys.stdout = open(output_file, 'w')

    print(s)


if __name__ == '__main__':
    input()
    process()
    output()