import os
import sys

input_file = os.path.join(sys.path[0], 'yte5k.inp')
output_file = os.path.join(sys.path[0], 'yte5k.out')

# Số lượng ghế, số lượng sự kiện
n = m = 0

# Mảng lưu các sự kiện V hoặc R
events = []

# Mảng lưu giá trị x đi kèm với loại sự kiện R
# event_index[i] = x nghĩa là sự kiện x được đính kèm với sự kiện i
event_index = []

# Tập hợp lưu số thứ tự của ghế, dùng để đánh dấu đã có người ngồi
occupied_chairs = set()

# Mảng lưu ánh xạ sự kiện và ghế được chọn
# event_chair[i] = c nghĩa là tại sự kiện i, ghế c được chọn ngồi
event_chair = []

# Mảng lưu số thứ tự ghế, dùng để output
result = []

def input_data():
    global n, m, events, event_index

    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().split())

        events = [0] * (m + 1)
        event_index = [0] * (m + 1)

        for i in range(1, m + 1):
            line = f.readline().strip()

            if len(line) == 1:
                events[i] = 'V'
            elif line[0] == 'R':
                event = line.split()
                events[i] = event[0]
                event_index[i] = int(event[1])


def process():
    global n, m, events, event_chair, occupied_chairs, result

    # Khởi tạo giá trị 0 cho toàn bộ mảng ánh xạ sự kiện - ghế
    event_chair = [0] * (m + 1)

    # Người đầu tiên vào khu vực chờ sẽ luôn chọn ghế số 1
    # Ghế 1 được chọn cho sự kiện 1
    event_chair[1] = 1

    # Đánh dấu ghế 1 đã có người ngồi
    occupied_chairs.add(1)

    # Nạp vào mảng result để output
    result.append(1)

    # Duyệt từng sự kiện i trong phạm vi [2..m]
    for i in range(2, m + 1):    
        # Nếu sự kiện i thuộc loại V
        if events[i] == 'V':
            # Biến tạm lưu ghế được chọn
            selected_chair = -1

            # Khoảng cách lớn nhất trong số các khoảng cách gần nhất
            max_distance = -1

            # Duyệt từng ghế (đã có lẫn chưa có người ngồi)
            for c in range(1, n + 1):
                # Nếu ghế c đã có người ngồi thì bỏ qua, xét ghế c tiếp theo
                if c in occupied_chairs:
                    continue

                # nearest là khoảng cách gần nhất từ ghế c đến các ghế đã có người ngồi 
                nearest = float('inf')
                
                # Duyệt từng ghế oc đã có người ngồi
                for oc in occupied_chairs:                
                    # Tính khoảng cách gần nhất từ ghế c đến các ghế oc
                    nearest = min(nearest, abs(c - oc))                

                # Nếu khoảng cách đến ghế gần nhất là lớn nhất
                if nearest > max_distance:                
                    # thì lưu giá trị lớn nhất mới
                    max_distance = nearest

                    # và chọn ghế c
                    selected_chair = c
                
                # Nếu các khoảng cách gần nhất đều là lớn nhất
                elif nearest == max_distance and c < selected_chair:                
                    # thì chọn ghế có số nhỏ nhất
                    selected_chair = c               

            # Đánh dấu đã có người ngồi cho ghế selected_chair
            occupied_chairs.add(selected_chair)

            # Lưu ghế đã chọn ứng với sự kiện i
            event_chair[i] = selected_chair

            # Nạp vào mảng result để output
            result.append(selected_chair)
        
        # Nếu sự kiện i thuộc loại R
        elif events[i] == 'R':
            # Lấy sự kiện x
            x = event_index[i]

            # Lấy số ghế của sự kiện x
            chair_to_free = event_chair[x]
            
            # Bỏ đánh dấu đã có nguòi ngồi
            occupied_chairs.remove(chair_to_free)

            # Đặt lại trạng thái ghế của sự kiện
            event_chair[x] = 0


def output():
    global result
    with open(output_file, 'w') as f:
        result_string = '\n'.join(map(str, result))
        f.write(result_string)


if __name__ == '__main__':
    input_data()
    process()
    output()