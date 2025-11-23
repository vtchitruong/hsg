import os
import sys
from bisect import bisect_right

input_file = os.path.join(sys.path[0], 'expfuel.inp')
output_file = os.path.join(sys.path[0], 'expfuel.out')

INF = 4 * 10**18

n, m = 0, 0

# nhiên liệu cho mỗi đơn vị khoảng cách
c = 0

# mảng điểm tập kết, gồm các tuple (toạ độ, nhiên liệu)
A = []

# mảng điểm thám hiểm (điểm đích)
D = []

# mảng toạ độ, tách ra từ mảng A
positions = []

# Mảng dùng để tính prefix min, dành cho các điểm nằm bên trái điểm đích
# Lưu min(b - c * a) từ trái sang
min_left = []

# Mảng dùng để tính suffix min, dành cho các điểm nằm bên phải điểm đích
# Lưu min(b + c * a) từ phải sang
min_right = []


def input():
    global n, m, c, A, D

    with open(input_file, 'r') as f:
        n, m, c = map(int, f.readline().split())

        for _ in range(n):
            position, fuel = map(int, f.readline().split())
            A.append((position, fuel))
        
        for _ in range(m):
            dj = int(f.readline())
            D.append(dj)


# Hàm tiền xử lý
def precompute():
    global A, c, min_left, min_right, positions

    # Sắp xếp điểm tập kết theo toạ độ tăng dần
    A.sort()

    # Tính prefix min, càng tiến sang phải càng nhỏ dần
    min_left = [INF] * n
    current_min = INF

    for i in range(n):
        value = A[i][1]  - c * A[i][0]
        current_min = min(current_min, value)
        min_left[i] = current_min
    

    # Tính suffix min, càng tiến sang trái càng nhỏ dần
    min_right = [INF] * n
    current_min = INF

    for i in range(n - 1, -1, -1):
        value = A[i][1] + c * A[i][0]
        current_min = min(current_min, value)
        min_right[i] = current_min
  
    # Vì hàm bisect không so sánh số nguyên (dj) với tuple (pos, fuel) được
    # nên ta tách riêng thành phần tọa độ ra
    positions = [item[0] for item in A]

# Hàm vừa xử lý vừa in kết quả ra tập tin
def process_output():
    global A, c, D, min_left, min_right

    with open(output_file, 'w') as f:
        results = []

        # Duyệt điểm thám hiểm D[j] của từng đội
        for dj in D:
            # Khởi tạo output của một đội
            answer = INF

            # Tìm vị trí k bằng danh sách 'positions' đã tách ra ở trên
            k = bisect_right(positions, dj)

            # Trường hợp 1: chọn điểm tập kết ở bên trái
            if k > 0:
                answer = min(answer, min_left[k - 1] + c * dj)
            
            # Trường hợp 2: chọn điểm tập kết ở bên phải
            if k < n: 
                answer = min(answer, min_right[k] - c * dj)
            
            results.append(answer)
        
        f.write('\n'.join(map(str, results)))
    

if __name__ == '__main__':
    input()
    precompute()
    process_output()