import os
import sys

input_file = os.path.join(sys.path[0], 'xdxung.inp')
output_file = os.path.join(sys.path[0], 'xdxung.out')

s = ''

# D[i][j] lưu giá trị true/false đối với chuỗi con s[i..j]
D = []

max_len = 0


def input_data():
    global s
    with open(input_file, 'r') as f:
        s = f.readline().strip()


def process():
    global s, D, max_len

    # Khởi tạo mảng D
    n = len(s)
    D = [[False] * n for _ in range(n)]

    # Khởi tạo D[i][i] cho tất cả chuỗi con có độ dài bằng 1
    for i in range(n):
        D[i][i] = True

    # Khởi tạo D[i][i+1] cho tất cả chuỗi con có độ dài bằng 2
    for i in range(n-1):
        D[i][i+1] = s[i] == s[i+1]

    # Duyệt từng độ dài, với độ dài từ 3 trở lên
    for length in range(3, n + 1):

        # Duyệt từng vị trí i, là vị trí bắt đầu của chuỗi con
        for i in range(n - length + 1):
            # j là vị trí kết thúc của chuỗi con
            j = i + length - 1

            # Nếu ký tự đầu và cuối của chuỗi con giống nhau và chuỗi con bên trong là đối xứng
            if s[i] == s[j] and D[i+1][j-1]:
                # thì chuỗi con [i..j] cũng là đối xứng
                D[i][j] = True

                # Cập nhật lại max_len nếu độ dài chuỗi con đối xứng đang xét lớn hơn max_len
                max_len = max(max_len, length)


def output():
    global max_len
    with open(output_file, 'w') as f:
        f.write(str(max_len))


if __name__ == '__main__':
    input_data()
    process()
    output()
