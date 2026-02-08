import os
import sys

input_file = os.path.join(sys.path[0], 'demkitu.inp')
output_file = os.path.join(sys.path[0], 'demkitu.out')

s = ''

# mảng tần số f (frequency) lưu số lần xuất hiện của các ký tự
f = [0] * 26


def input():
    global s

    sys.stdin = open(input_file, 'r')

    s = sys.stdin.read()


def process():
    global s, f

    # Duyệt từng ký tự c của chuỗi s
    for c in s:
        # Nếu c là ký tự a..z thì cập nhật số lần xuất hiện của nó
        f[ord(c) - ord('a')] += 1


def output():
    global f

    sys.stdout = open(output_file, 'w')

    for i in range(26):
        if f[i] > 0:
            print(f'{chr(i + ord('a'))} {f[i]}')


if __name__ == '__main__':
    input()
    process()
    output()
