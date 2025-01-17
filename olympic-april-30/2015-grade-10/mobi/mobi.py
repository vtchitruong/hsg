import os
import sys

input_file = os.path.join(sys.path[0], 'mobi.inp')
output_file = os.path.join(sys.path[0], 'mobi.out')

n = 0
k = 0
locations = []
max_user_number = 0


def input_data():
    with open(input_file, 'r') as f:
        global n, k, locations

        n, k = map(int, f.readline().split())

        locations = [tuple(map(int, f.readline().split())) for _ in range(n)]


def process():
    global n, k, locations, max_user_number

    # Sắp xếp các điểm theo tọa độ x tăng dần
    locations.sort(key=lambda loc: loc[0])

    # Biến lưu số lượng người dùng của cửa sổ đang xét
    user_number = 0

    # Biến lưu vị trí bắt đầu cửa sổ
    left = 0

    # Duyệt từng khu dân cư bằng mốc phải của cửa sổ
    for right in range(n):
        # Cập nhật số lượng người dùng của cửa sổ
        user_number += locations[right][1]

        # Nếu khoảng cách giữa hai điểm lớn hơn 2k
        while locations[right][0] - locations[left][0] > 2 * k:
            # thì giảm số lượng người dùng của cửa sổ
            user_number -= locations[left][1]

            # và tăng vị trí bắt đầu cửa sổ
            left += 1

        # Cập nhật số lượng người dùng lớn nhất
        max_user_number = max(max_user_number, user_number)


def output():
    with open(output_file, 'w') as f:
        f.write(f'{max_user_number}')


if __name__ == '__main__':
    input_data()
    process()
    output()