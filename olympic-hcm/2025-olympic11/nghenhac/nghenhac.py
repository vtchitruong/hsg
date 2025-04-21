import os
import sys

input_file = os.path.join(sys.path[0], 'nghenhac.inp')
output_file = os.path.join(sys.path[0], 'nghenhac.out')

n = k = 0
songs = []

# số lượng bài hát tối đa cần tìm
max_count = 0


def input_data():
    global n, k, songs

    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())
        songs = list(map(int, f.readline().split()))


def process():
    global n, k, songs, max_count

    # con trỏ bên trái (con trỏ bắt đầu)
    left = 0

    # tổng thời gian của các bài hát trong cửa sổ trượt đang xét
    current_sum = 0

    # số lượng bài hát trong cửa sổ trượt đang xét
    current_count = 0

    # Duyệt con trỏ bên phải (con trỏ kết thúc)
    for right in range(n):
        # Tính tổng thời gian đang xét
        current_sum += songs[right]

        # Nếu tổng thời gian đang xét vượt quá thời gian cho phép
        while current_sum > k and left <= right:        
            # thì loại bỏ bài hát bên trái
            current_sum -= songs[left]

            # Thu hẹp cửa sổ nhằm làm tổng thời gian hợp lệ trở lại
            left += 1
        
        # Tính số lượng bài hát đang xét
        current_count = right - left + 1

        # Cập nhật số lượng bài hát tối đa
        max_count = max(max_count, current_count)


def output():
    global max_count

    with open(output_file, 'w') as f:
        f.write(str(max_count))


if __name__ == '__main__':
    input_data()
    process()
    output()
