import os
import sys

input_file = os.path.join(sys.path[0], 'chuanhoaxau.inp')
output_file = os.path.join(sys.path[0], 'chuanhoaxau.out')

# chuỗi ban đầu
prop_string = ''

# chuỗi sau khi biến đổi
join_string = ''


def input():
    global prop_string

    with open(input_file, 'r') as f:
        prop_string = f.readline()


def process():
    global prop_string, join_string

    # Duyệt từng ký tự trong chuỗi ban đầu
    for i in range(len(prop_string)):
        # ký tự đang xét
        current = prop_string[i]

        # Nếu ký tự đang xét là in hoa
        if current.isupper():
            # Nếu không phải ký tự in hoa đầu tiên thì thêm gạch
            if i > 0:
                join_string += '_'

            # Chuyển ký tự in hoa thành thường
            join_string += current.lower()
        else:
            join_string += current


def output():
    global join_string

    with open(output_file, 'w') as f:
        f.write(join_string)


if __name__ == '__main__':
    input()
    process()
    output()