import os
import sys

input_file = os.path.join(sys.path[0], 'tudai.inp')
output_file = os.path.join(sys.path[0], 'tudai.out')

line = ''
longest_word = ''
max_length = 0

def input():
    global line

    with open(input_file, 'r') as f:
        line = f.readline().strip()


def process():
    global line, longest_word, max_length

    # Tách chuỗi line thành list gồm các từ
    words = line.split()

    # Duyệt từng từ trong list words
    for word in words:
        length = len(word)

        if length >= max_length:
            max_length = length
            longest_word = word


def output():
    global longest_word, max_length

    with open(output_file, 'w') as fo:
        fo.write(f'{max_length}\n{longest_word}')


if __name__ == '__main__':
    input()
    process()
    output()