import os
import sys

input_file = os.path.join(sys.path[0], 'river.inp')
output_file = os.path.join(sys.path[0], 'river.out')

river = ''

# số lần vượt sông ít nhất
result = 0


def input_data():
    global river

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    river = '0' + next(iterator)


def process():
    global river, Left, Right, result
    
    n = len(river)
    
    # Khởi tạo vị trí xuất phát
    current_left = 0
    current_right = 1

    # Duyệt từng nhánh sông từ 1 đến n - 1
    for i in range(1, n):
        # Khởi tạo biến tạm
        next_left = 0
        next_right = 0

        if river[i] == 'L': 
            next_left = min(current_left + 1, current_right + 1)
            next_right = min(current_left + 1, current_right)
        elif river[i] == 'R':        
            next_left = min(current_left, current_right + 1)
            next_right = min(current_left + 1, current_right + 1)
        elif river[i] == 'B':        
            next_left = min(current_left + 1, current_right + 2)
            next_right = min(current_left + 2, current_right + 1)        

        # Cập nhật current để chuẩn bị cho lần lặp tiếp theo
        current_left = next_left
        current_right = next_right    

    # Bước cuối cùng để đến nhà ngoại
    result = min(current_left + 1, current_right)


def output():
    sys.stdout = open(output_file, 'w')

    print(result)


if __name__ == '__main__':
    input_data()
    process()
    output()
