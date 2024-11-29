import os
import sys

input_file = os.path.join(sys.path[0], 'kite.inp')
output_file = os.path.join(sys.path[0], 'kite.out')

n = 0

# Mảng lưu các độ cao từ input 
heights = []

# Mảng lưu thứ hạng
result = []


# Hàm dùng để tìm vị trí trong danh sách A sẽ chèn value vào và bảo đảm A luôn giảm dần
def position(A, value):
    # Duyệt từng phần tử trong danh sách A
    for i, element in enumerate(A):
        # Nếu gặp phần tử nhỏ hơn
        if element < value:
            # thì trả về vị trí của phần tử đó
            return i
    
    # Ngược lại, không có phần tử nhỏ hơn, thì trả về -1
    return -1


def input_process():
    global n, heights

    with open(input_file, 'r') as f:
        n = int(f.readline())

        # Đọc độ cao của diều đầu tiên
        h = int(f.readline())
        heights.append(h)

        # Diều đầu tiên được xếp hạng 1
        rank = 1
        result.append(rank)

        # Duyệt từng dòng còn lại của dữ liệu đầu vào
        for i in range(1, n):
            # Đọc độ cao của một diều mới
            h = int(f.readline())

            # Xác định vị trí sẽ chèn vào
            pos_to_insert = position(heights, h)

            # Nếu không có vị trí chèn phù hợp
            if pos_to_insert == -1:
                # thì thêm vào cuối danh sách heights
                heights.append(h)
            else:
                heights.insert(pos_to_insert, h)

            # Tính thứ hạng của h vừa nạp bằng cách dựa vào chỉ số
            rank = heights.index(h) + 1

            # Ghi nhận thứ hạng
            result.append(rank)


def output():
    global result
    
    with open(output_file, 'w') as f:
        result_string = '\n'.join(map(str, result))
        f.write(result_string)


if __name__ == '__main__':
    input_process()
    output()