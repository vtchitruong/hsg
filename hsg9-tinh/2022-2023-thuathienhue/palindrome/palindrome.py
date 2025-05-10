import os
import sys

input_file = os.path.join(sys.path[0], 'palindrome.inp')
output_file = os.path.join(sys.path[0], 'palindrome.out')

s = ''

# độ dài lớn nhất cần tìm
max_length = 1


def input():
    global s

    with open(input_file, 'r') as f:
        s = f.readline()


def process():
    global s, max_length

    n = len(s)

    # Duyệt từng ký tự của s
    for i in range(n):
        # Kiểm tra chuỗi đối xứng có độ dài lẻ
        left = i
        right = i

        # Nếu hai đầu left và right giống nhau
        while left >= 0 and right < n and s[left] == s[right]:
            # thì tính độ dài từ left đến right
            tmp_length = right - left + 1

            # Cập nhật độ dài lớn nhất
            max_length = max(max_length, tmp_length)

            # Tiếp tục mở rộng hai bên
            left -= 1
            right += 1

        # Kiểm tra chuỗi đối xứng có độ dài chẵn
        left = i
        right = i + 1

        # Nếu hai đầu left và right giống nhau
        while left >= 0 and right < 1 and s[left] == s[right]:
            # thì tính độ dài từ left đến right
            tmp_length = right - left + 1

            # Cập nhật độ dài lớn nhất
            max_length = max(max_length, tmp_length)

            # Tiếp tục mở rộng hai bên
            left -= 1
            right += 1


def output():
    global max_length

    with open(output_file, 'w') as f:
        f.write(str(max_length))


if __name__ == '__main__':
    input()
    process()
    output()