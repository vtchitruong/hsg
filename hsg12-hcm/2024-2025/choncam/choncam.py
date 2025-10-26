import os
import sys

input_file = os.path.join(sys.path[0], 'choncam3.inp')
output_file = os.path.join(sys.path[0], 'choncam3.out')

n = 0

# mảng tần số f lưu số lượng đang xét của các loại cam
f = [0] * 6

# mảng continuous dùng để đánh dấu tính liên tiếp của loại cam
continuous = [False] * 6

# output
max_oranges = 0
best_type = 1


# Hàm dùng để đánh dấu tính liên tiếp của loại cam
def mark(first, second):
    global continuous

    # Đặt lại cho tất cả đều là không liên tiếp
    continuous = [False] * 6

    # Đánh dấu liên tiếp cho hai loại đang xét
    continuous[first] = continuous[second] = True


# Hàm dùng để xét nhiều nhất
def consider(current_oranges, current_type):
    global max_oranges, best_type

    if current_oranges == max_oranges:
        # Nếu loại đang xét bằng với giá trị lớn nhất
        # thì lấy loại có nhãn nhỏ nhất
        best_type = min(current_type, best_type)
    elif current_oranges > max_oranges:
        # Nếu loại đang xét lớn hơn giá trị lớn nhất
        # thì cập nhật giá trị lớn nhất mới và loại mới
        max_oranges = current_oranges
        best_type = current_type


def input_process():
    global n, f, continuous, max_oranges, best_type

    with open(input_file, 'r') as fi:
        n = int(fi.readline())

        # Duyệt từng khay
        for i in range(n):
            first, second = map(int, fi.readline().split())

            # Nếu là loại cam thứ nhất đang liên tục thì tăng tần số lên 1
            # Ngược lại, không liên tục, thì đếm lại từ đầu
            if continuous[first]:
                f[first] += 1
            else:
                f[first] = 1

            # Xét xem đã đạt được nhiều nhất hay chưa
            consider(f[first], first)

            # Nếu là loại cam thứ hai đang liên tục thì tăng tần số lên 1
            # Ngược lại, không liên tục, thì đếm lại từ đầu
            if continuous[second]:
                f[second] += 1
            else:
                f[second] = 1

            # Xét xem đã đạt được nhiều nhất hay chưa
            consider(f[second], second)
            
            # Đánh dấu lại tính liên tục cho từng loại cam
            mark(first, second)


def output():
    global max_oranges, best_type

    with open(output_file, 'w') as fo:
        fo.write(f'{max_oranges} {best_type}')


if __name__ == '__main__':
    input_process()
    output()
