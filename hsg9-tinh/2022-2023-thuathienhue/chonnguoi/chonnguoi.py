import os
import sys

input_file = os.path.join(sys.path[0], 'chonnguoi.inp')
output_file = os.path.join(sys.path[0], 'chonnguoi.out')

n = k = 0

# biến lưu một tổ hợp
C = []

# biến đếm số lượng tổ hợp
number_of_combinations = 0


def input():
    global n, k

    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())


# Hàm phát sinh tổ hợp
def combination(A):
    global n, k

    # Duyệt từ phần tử cuối ngược về đầu
    for i in range(k - 1, -1, -1):
        # Kiểm tra xem A[i] có thể tăng lên mà vẫn bảo đảm các phần tử sau nó có thể được cập nhật hợp lệ
        # N - (K - i - 1) là giá trị tối đa mà A[i] có thể nhận để sau khi tăng, vẫn còn đủ giá trị lớn hơn cho các phần tử sau
        if A[i] < n - (k - i - 1):
            A[i] += 1

            # Cập nhật các phần tử sau A[i] để chúng là các giá trị nhỏ nhất có thể, mà vẫn lớn hơn phần tử trước đó
            for j in range(i + 1, k):
                A[j] = A[j - 1] + 1

            # Trả về true nhằm cho biết một tổ hợp mới đã được sinh ra
            return True
    
    # Nếu không có phần tử nào có thể tăng, đồng nghĩa tổ hợp hiện tại là tổ hợp cuối cùng
    return False


def process_output():
    global n, k, number_of_combinations

    # Khởi tạo bộ ban đầu: 1, 2, 3, ..., k
    C = [0] * k

    for i in range(k):
        C[i] = i + 1

    # Liệt kê và ghi các tổ hợp ra file
    with open(output_file, 'w') as f:
        while True:
            for i in range(k):
                f.write(str(C[i]))
                
                if i < k - 1:
                    f.write(' ')

            f.write('\n')
            number_of_combinations += 1

            if not combination(C):
                break
        
        f.write(str(number_of_combinations))


if __name__ == '__main__':
    input()
    process_output()