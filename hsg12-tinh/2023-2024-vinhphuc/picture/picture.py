import os
import sys

input_file = os.path.join(sys.path[0], 'picture.inp')
output_file = os.path.join(sys.path[0], 'picture.out')

n, m = 0, 0
pictures = []  # bức tranh (size, value)
frames = []  # khung tranh

# Biến cnt dùng để đếm số bức tranh đặt vào khung
cnt = 0

def input_data():
    global n, m, pictures, frames
    
    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().split())
        
        for _ in range(n):
            size, value = map(int, f.readline().split())
            pictures.append((size, value))
        
        frames = list(map(int, f.readlines()))


def process():
    global cnt
    
    # Sắp xếp các bức tranh theo kích thước tăng dần
    # Nếu cùng kích thước thì sắp xếp theo giá trị tăng dần
    pictures.sort(key=lambda x: (x[0], x[1]))
    
    # Sắp xếp các khung tranh theo kích thước tăng dần
    frames.sort()

    # Biến i dùng để duyệt các bức tranh
    i = 0
    
    # Giá trị của bức tranh đặt vào khung trước đó
    previous_value = 0

    # Duyệt các khung tranh
    for f in frames:
        # uyệt các bức tranh có kích thước phù hợp với khung
        while i < n and pictures[i][0] <= f:
            # Nếu tìm thấy bức tranh thoả về kích thước lẫn giá trị
            if pictures[i][1] >= previous_value:
                # Đặt tranh vào khung
                cnt += 1

                # Lưu giá trị của bức tranh vừa đặt vào khung
                previous_value = pictures[i][1]

                # Xét bức tranh tiếp theo
                i += 1

                # Ngắt vòng lặp while để xét khung tranh tiếp theo
                break

            # Xét bức tranh tiếp theo
            i += 1


def output():
    with open(output_file, 'w') as f:
        f.write(str(cnt))


if __name__ == '__main__':
    input_data()
    process()
    output()
