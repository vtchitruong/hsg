import os
import sys
from collections import deque

input_file = os.path.join(sys.path[0], 'daydep.inp')
output_file = os.path.join(sys.path[0], 'daydep.out')

MAX = 100000

n = 0
A = []

# mảng tần số lưu số lần xuất hiện của một phần tử A[i] trong cửa sổ trượt [left..right]
f = [0] * (MAX + 1)

# biến lưu số lượng dãy con cần tìm
count = 0


def input():
    global n, A

    with open(input_file, 'r') as f:
        n = int(f.readline())

        A = list(map(int, f.readline().split()))


def process():
    global n, A, count

    # vị trí bắt đầu của cửa sổ trượt
    left = 0

    # Duyệt từng vị trí kết thúc cửa sổ trượt
    for right in range(0, n):
        # Thêm A[right] vào cửa sổ và cập nhật số lần xuất hiện
        f[A[right]] += 1

        # Di chuyển con trỏ trái để loại bỏ phần tử trùng nhau
        while left <= right and f[A[right]] > 1:
            f[A[right]] -= 1
            left += 1

        # Cửa sổ [left..right] hiện không còn phần tử trùng nhau
        
        # Khai báo deque dùng để tìm phần tử nhỏ nhất trong dãy con [k..right]
        # deque lưu chỉ số k thoả điều kiện các A[k] trong deque tăng dần
        dq_min = deque()

        # Khai báo deque dùng để tìm phần tử lớn nhất trong dãy con [k..right]
        # deque lưu chỉ số k thoả điều kiện các A[k] trong deque giảm dần
        dq_max = deque()

        # Duyệt từng vị trí k, từ right ngược về left
        for k in range(right, left - 1, -1):
            # Cập nhật dq_min sao cho tăng dần
            while dq_min and A[dq_min[-1]] >= A[k]:
                dq_min.pop()

            # Nạp chỉ số k hợp lệ vào cuối hàng
            dq_min.append(k)

            # Cập nhật dq_max sao cho giảm dần
            while dq_max and A[dq_max[-1]] <= A[k]:
                dq_max.pop()
            
            # Nạp chỉ số k hợp lệ vào cuối hàng
            dq_max.append(k)

            # Kiểm tra [k..right] có phải là dãy đẹp hay không
            if A[dq_max[0]] - A[dq_min[0]] == right - k:
                count += 1


def output():
    global count

    with open(output_file, 'w') as f:
        f.write(str(count))


if __name__ == '__main__':
    input()
    process()
    output()