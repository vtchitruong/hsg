import os
import sys

input_file = os.path.join(sys.path[0], 'river.inp')
output_file = os.path.join(sys.path[0], 'river.out')

River = ''

# Số lần vượt sông ít nhất để đến được vị trí i ở bờ trái của sông
Left = []

# Số lần vượt sông ít nhất để đến được vị trí i ở bờ phải của sông
Right = []

# Số lần vượt sông ít nhất
result = 0


def input_data():
    global River

    with open(input_file, 'r') as f:
        River = f.readline().strip()
        River = '0' + River


def process():
    global River, Left, Right, result
    n = len(River)
    Left = [0] * n
    Right = [0] * n

    # Khởi tạo vị trí 0 là vị trí xuất phát
    Left[0] = 0
    Right[0] = 1

    # Duyệt từng nhánh sông (ký tự của chuỗi River) trong phạm vi [1..n - 1]
    # Xét ba trường hợp: nhánh sông ở bờ trái, ở bờ phải và ở cả hai bờ
    for i in range(1, n):
        if River[i] == 'L':
            # Có hai cách đi đến vị trị i ở bờ trái:
            # Cách 1: vượt nhánh sông ở bờ trái
            # Cách 2: vượt sông từ bờ phải sang bờ trái
            Left[i] = min(Left[i - 1] + 1, Right[i - 1] + 1)

            # Có hai cách đi đến vị trị i ở bờ phải:
            # Cách 1: vượt sông từ bờ trái sang bờ phải
            # Cách 2: không vượt lần nào, vì vẫn đang ở bờ phải
            Right[i] = min(Left[i - 1] + 1, Right[i - 1])
        elif River[i] == 'R':
            # Có hai cách đi đến vị trị i ở bờ trái:
            # Cách 1: không vượt lần nào, vì vẫn đang ở bờ trái
            # Cách 2: vượt sông từ bờ phải sang bờ trái
            Left[i] = min(Left[i - 1], Right[i - 1] + 1)

            # Có hai cách đi đến vị trị i ở bờ phải:
            # Cách 1: vượt sông từ bờ trái sang bờ phải
            # Cách 2: vượt nhánh sông ở bờ phải
            Right[i] = min(Left[i - 1] + 1, Right[i - 1] + 1)
        elif River[i] == 'B':
            # Có hai cách đi đến vị trị i ở bờ trái:
            # Cách 1: vượt nhánh sông ở bờ trái
            # Cách 2: vượt nhánh sông ở bờ phải, rồi vượt sông từ bờ phải sang bờ trái
            Left[i] = min(Left[i - 1] + 1, Right[i - 1] + 2)

            # Có hai cách đi đến vị trị i ở bờ phải:
            # Cách 1: vượt nhánh sông ở bờ trái, rồi vượt sông từ bờ trái sang bờ phải
            # Cách 2: vượt nhánh sông ở bờ phải
            Right[i] = min(Left[i - 1] + 2, Right[i - 1] + 1)

    # Bước cuối cùng để đến nhà ngoại
    # Cách 1: vượt sông từ bờ trái sang bờ phải
    # Cách 2: đang ở bờ phải nên không vượt sông nữa
    result = min(Left[n - 1] + 1, Right[n - 1])


def output():
    with open(output_file, 'w') as f:
        f.write(f'{result}')


if __name__ == '__main__':
    input_data()
    process()
    output()
