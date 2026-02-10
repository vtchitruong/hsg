import os
import sys

input_file = os.path.join(sys.path[0], 'xaucon.inp')
output_file = os.path.join(sys.path[0], 'xaucon.out')

s = ''
result = 0


def input():
    global s

    with open(input_file, 'r') as f:
        s = f.readline()


# Hàm kiểm tra nguyên âm
def is_vowel(c):
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'


def process():
    global s, result

    vowel = 0
    consonant = 0

    # Duyệt chuỗi để đếm số nguyên âm và số phụ âm
    for i in range(len(s)):
        if is_vowel(s[i]):
            vowel += 1
        else:
            consonant += 1

    # Tính số chuỗi con đặc biệt
    result = vowel * consonant


def output():
    global result

    with open(output_file, 'w') as f:
        f.write(f'{result}')


if __name__ == '__main__':
    input()
    process()
    output()