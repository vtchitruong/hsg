import os
import sys

input_file = os.path.join(sys.path[0], 'vitinh.inp')
output_file = os.path.join(sys.path[0], 'vitinh.out')

n = 0
total_digits = 0


def input_data():
    global n

    with open(input_file, 'r') as f:
        n = int(f.readline())


def process():
    global n, total_digits

    # các số luỹ thừa của 10: 1, 10, 100, 1000, 10000, ...
    power_of_ten = 1

    # giới hạn trên của phạm vi đang xét: 9, 99, 999, 9999, ...
    bound = 0

    # số chữ số trong phạm vi đang xét: 1, 2, 3, 4, ...
    number_of_digits = 1

    # số lượng số trong phạm vi đang xét
    amount = 0

    while (True):
        # Tính giới hạn trên của phạm vi đang xét: 9, 99, 999, 9999, ...
        bound = power_of_ten * 10 - 1

        # So sánh n và giới hạn trên
        if n >= bound:
            # Tính số lượng số trong phạm vi đang xét: 9, 90, 900, 9000, ...
            amount = 9 * power_of_ten

            # Lấy số lượng số x số chữ số, rồi cộng dồn vào kết quả
            total_digits += amount * number_of_digits
        else:
            # Tính số lượng số trong phạm vi đang xét: 9, 90, 900, 9000, ...
            amount = n - power_of_ten + 1

            # Lấy số lượng số x số chữ số, rồi cộng dồn vào kết quả
            total_digits += amount * number_of_digits

            # Thoát vòng lặp, kết thúc chương trình
            break

        # Tăng số chữ số để xét phạm vi tiếp theo
        number_of_digits += 1

        # Nhân thêm 10
        power_of_ten *= 10

        # Điều kiện dừng vòng lặp
        if power_of_ten > n:
            break


def output():
    global n, total_digits

    with open(output_file, 'w') as f:
        f.write(f'{total_digits}')


if __name__ == '__main__':
    input_data()
    process()
    output()