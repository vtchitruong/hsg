import os
import sys

input_file = os.path.join(sys.path[0], 'tgv.inp')
output_file = os.path.join(sys.path[0], 'tgv.out')

n = 0

# Mảng lưu các tung độ có cùng hoành độ x
x_axis = []

# Mảng lưu các hoành độ có cùng hoành độ y
y_axis = []

# số tam giác vuông cần tìm
result = 0


def input_data():
    global n, x_axis, y_axis

    with open(input_file, 'r') as f:
        n = int(f.readline())

        for _ in range(n):
            x, y = map(int, f.readline().split())

            if x >= len(x_axis):
                x_axis.extend([] for _ in range(x - len(x_axis) + 1))
            
            x_axis[x].append(y)

            if y >= len(y_axis):
                y_axis.extend([] for _ in range(y - len(y_axis) + 1))

            y_axis[y].append(x)


def process():
    global x_axis, y_axis, result

    # Duyệt từng hoành độ x
    for x in range(1, len(x_axis)):
        # Nếu tồn tại điểm có hoành độ x đang xét 
        if x_axis[x]:
            # Tính số cạnh song song trục tung, tức có cùng hoàng độ x
            vertical_edge_number = len(x_axis[x]) - 1

            # Duyệt từng tung độ y có cùng hoành độ x đang xét
            for y in x_axis[x]:
                # Nếu tồn tại điểm có tung độ y đang xét
                if  y_axis[y]:
                    # Tính số cạnh song song trục hoành, tức có cùng tung độ y
                    horizontal_edge_number = len(y_axis[y]) - 1

                    # Tính số tam giác vuông tạo thành
                    result += vertical_edge_number * horizontal_edge_number


def output():
    global result
    with open(output_file, 'w') as f:
        f.write(f'{result}')


if __name__ == '__main__':
    input_data()
    process()
    output()
            
        
    

