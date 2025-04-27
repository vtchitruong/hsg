import os
import sys

input_file = os.path.join(sys.path[0], 'demkitu.inp')
output_file = os.path.join(sys.path[0], 'demkitu.out')

s = ''

# mảng tần số f (frequency) lưu số lần xuất hiện của các ký tự
f = [0] * 26


def input():
    global s

    with open(input_file, 'r') as f:
        s = f.readline()


def process():
    global s, f

    # Duyệt từng ký tự của chuỗi s
    for i in range(len(s)):
        # vỨng với ký tự s[i], cập nhật số lần xuất hiện của nó
        f[ord(s[i]) - ord('a')] += 1


def output():
    global f

    with open(output_file, 'w') as fo:
        for i in range(26):
            if f[i] != 0:
                fo.write(f'{chr(i + ord("a"))} {f[i]}\n')


if __name__ == '__main__':
    input()
    process()
    output()
