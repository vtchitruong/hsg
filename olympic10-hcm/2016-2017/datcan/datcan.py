import os
import sys

input_file = os.path.join(sys.path[0], 'datcan.inp')
output_file = os.path.join(sys.path[0], 'datcan.out')

n = 0
p = []
result = 0

# tổng khối lượng các quả cân
total = 0


def input():
    global n, p, total

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iteration = iter(data)

    n = int(next(iteration))
    
    p = [0] * n

    for i in range(n):
        x = int(next(iteration))
        p[i] = x

        total += p[i]


def process():
    global result

    # Khởi tạo mảng prev_d để lưu số cách ở bước trước đó
    prev_d = [0] * (2 * total + 1)

    # Chưa đặt quả cân nào lên đĩa, tính là 1 cách
    prev_d[total] = 1

    # Duyệt từng quả cân
    for i in range(n):
        w = p[i]

        # Khởi tạo mảng d để lưu số cách ở bước hiện đang xét
        d = [0] * (2 * total + 1)

        # Duyệt từng mức độ chênh lệch khối lượng của hai đĩa
        for j in range(2 * total + 1):
            if prev_d[j] > 0:            
                # Trường hợp 0: không đặt thêm quả cân
                d[j] += prev_d[j]

                # Trường hợp 1: đặt quả cân w lên đĩa trái
                if j + w < 2 * total + 1:
                    d[j + w] += prev_d[j]

                # Trường hợp 2: đặt quả cân w lên đĩa phải
                if j - w >= 0:
                    d[j - w] += prev_d[j]           
        
        # Cập nhật mảng d để chuẩn bị cho lần lặp tiếp theo
        prev_d = d
    
    result = (prev_d[total] - 1) // 2


def output():
    sys.stdout = open(output_file, 'w')

    print(result)


if __name__ == '__main__':
    input()
    process()
    output()