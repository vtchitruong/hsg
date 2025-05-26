import os
import sys

input_file = os.path.join(sys.path[0], 'matthu.inp')
output_file = os.path.join(sys.path[0], 'matthu.out')

n = 0
encoded = decoded = ''


def input():
    global n, encoded, decoded

    with open(input_file, 'r') as f:
        n = int(f.readline())

        encoded = f.readline()


# Hàm dùng để đảo ngược chuỗi
def reverse_string(s):
    return s[::-1]


def process():
    global n, encoded, decoded

    word = ''
    digit = ' ' # ký tự khoảng trắng

    # Duyệt từng ký tự trong chuỗi encoded
    for i in range(n):
        # Nếu ký tự đang xét là 1 hoặc 2
        if encoded[i] == '1' or encoded[i] == '2':
            # Nếu word hiện hành khác rỗng
            if word:
                # thì giữa nguyên hoặc đảo chuỗi
                if digit == '1':
                    decoded += word
                elif digit == '2':
                    decoded += reverse_string(word)

                # Nếu decoded khác rỗng thì thêm ký tự khoảng trắng
                if decoded:
                    decoded += ' '
                    
                # Khởi tạo word rỗng
                word = ''

            digit = encoded[i]

        else:
            # Ngược lại, nếu không phải ký tự số thì ghép ký tự đang xét vào word
            word += encoded[i]
    
    # Xử lý từ cuối cùng
    if word:
        if digit == '1':
            decoded += word
        elif digit == '2':
            decoded += reverse_string(word)

    # Loại bỏ ký tự khoảng trắng ở cuối nếu có
    if decoded and decoded[-1] == ' ':
        decoded = decoded[:-1]


def output():
    global decoded

    with open(output_file, 'w') as f:
        f.write(decoded)


if __name__ == '__main__':
    input()
    process()
    output()