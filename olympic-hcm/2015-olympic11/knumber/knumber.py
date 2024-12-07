import os
import sys

input_file = os.path.join(sys.path[0], 'knumber1.inp')
output_file = os.path.join(sys.path[0], 'knumber1.out')

k = 0
result = ''


def input_data():
    global k
    with open(input_file, 'r') as f:
        k = int(f.readline())


def process():
    global k, result

    # Số lượng chữ số tích luỹ khi tăng độ dài của các số nguyên tạo thành
    cumulative_digits = 0

    # Độ dài (số chữ số) của một số nguyên tạo thành
    length = 1

    while True:
        # Tính số lượng số nguyên tạo thành ứng với độ dài length
        if length == 1:
            # Với độ dài 1, chỉ có 0 và 5
            integer_amount = 2
        else:
            # Chữ số đầu là 5, các chữ số còn lại là 0 hoặc 5
            integer_amount = 2 ** (length - 1)

        # Số lượng chữ số của nhóm số nguyên có cùng độ dài
        digit_amount = integer_amount * length

        # Nếu vượt quá vị trí k thì ngắt vòng lặp
        if cumulative_digits + digit_amount > k:
            break

        # Tính số lượng chữ số tích luỹ được và không vượt quá vị trí k
        cumulative_digits += digit_amount

        # Tăng độ dài để xét nhóm số nguyên tiếp theo
        length += 1

    # j cũng là vị trí k nhưng xét riêng trong nhóm số nguyên có cùng độ dài length
    j = k - cumulative_digits
    
    # Vị trí của số nguyên liên quan (có chứa vị trí j) tính trong nhóm có cùng độ dài length
    integer_pos = j // length

    # Tạo số nguyên có liên quan
    if length == 1:
        integers = ['0', '5']
        integer_string = integers[integer_pos]
    else:
        # Tạo chữ số đầu tiên, luôn là '5'
        first_digit = '5'

        # Số chữ số còn lại cần tạo
        remaining_length = length - 1

        # Chuỗi dùng để định dạng
        format_string = '{:0' + str(remaining_length) + 'b}'
        
        # Tạo chuỗi nhị phân ứng với số nguyên cần tạo
        binary = format_string.format(integer_pos)

        # Tạo các chữ số còn lại, thay 1 bằng 5
        remaining_digits = ''.join('5' if c == '1' else '0' for c in binary)

        # Số nguyên tạo thành ở dạng chuỗi
        integer_string = first_digit + remaining_digits

    # Chữ số cần tìm
    target_pos = j % length
    result = integer_string[target_pos]


def output():
    with open(output_file, 'w') as f:
        f.write(result)


if __name__ == '__main__':
    input_data()
    process()
    output()
