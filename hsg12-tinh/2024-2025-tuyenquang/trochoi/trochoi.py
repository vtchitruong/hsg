import os
import sys

input_file = os.path.join(sys.path[0], 'trochoi.inp')
output_file = os.path.join(sys.path[0], 'trochoi.out')

n = k = q = 0

# Mảng lưu học sinh tham gia trò chơi
students = []

# Mảng chênh lệch (difference array) (dùng kiểu dict để tránh trường hợp lớn)
diff = {}

# Mảng lưu tần số xuất hiện (dùng kiểu dict để tránh trường hợp lớn)
join = {}


def input_data():
    global n, k, q, students

    with open(input_file, 'r') as file:
        n, k, q = map(int, file.readline().split())

        for i in range(1, k + 1):
            l, r = map(int, file.readline().split())

            # Cộng 1 vào học sinh l
            diff[l] = diff.get(l, 0) + 1

            # Trừ 1 vào học sinh r + 1
            diff[r + 1] = diff.get(r + 1, 0) - 1

        # Đọc thông tin các học sinh cần kiểm tra
        students = list(map(int, file.readline().split()))


# Áp dụng mảng chênh lệch và mảng cộng dồn
def process():
    global join

    # Khởi tạo giá trị cộng dồn hiện tại
    current = 0

    # Duyệt từng phần tử của mảng chênh lệch
    for key in sorted(diff.keys()):
        # Gán biến nhằm làm rõ nghĩa hơn
        student_id = key
        difference = diff[key]

        # Thực hiện cộng dồn
        current += difference
        join[student_id] = current


def output():
    global students

    with open(output_file, 'w') as file:
        for student in students:
            # Tìm học sinh đầu tiên có mã số lớn hơn students[i]
            keys = sorted(join.keys())
            it = next((key for key in keys if key > student), None)

            # Nếu không tìm thấy học sinh students[i] thì in ra 0
            if it is None:
                file.write('0')
            else:
                # Ngược lại, tìm thấy, thì in ra số trò chơi mà học sinh students[i] tham gia
                prev_key = keys[keys.index(it) - 1] if keys.index(it) > 0 else None
                if prev_key is None:
                    file.write('0')
                else:
                    file.write(f'{join[prev_key]}')


if __name__ == '__main__':
    input_data()
    process()
    output()