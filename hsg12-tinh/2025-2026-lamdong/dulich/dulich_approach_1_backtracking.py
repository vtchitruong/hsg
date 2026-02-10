import os
import sys

input_file = os.path.join(sys.path[0], 'dulich.inp')
output_file = os.path.join(sys.path[0], 'dulich.out')

INF = float('inf')

n = 0
c = []

# mảng đánh dấu các điểm du lịch đã đi qua
visited = []

# chi phí nhỏ nhất của một cạnh bất kỳ, dùng cho kỹ thuật nhánh cận
c_min = INF

# chi phí tối ưu, dùng để output
result = INF


def input():
    global n, c, c_min

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))

    c = [[0] * (n + 1) for _ in range(n + 1)]

    for u in range(1, n + 1):
        for v in range(1, n + 1):
            x = int(next(iterator))
            c[u][v] = x

            if u != v and c[u][v] < c_min:            
                c_min = c[u][v]
            

def traverse(u, counter, c_current):
    global n, c_min, visited, result

    # Nếu chi phí hiện tại + (số cạnh còn thiếu * giá cạnh nhỏ nhất) >= kết quả thì cắt nhánh
    if c_current + (n - counter + 1) * c_min >= result:
        return

    # Nếu đã đi qua đủ n địa điểm
    if counter == n:
        if c_current < result:
            result = c_current

        return
    
    for v in range(1, n + 1):
        if not visited[v]:
            # Thử ghé thăm điểm v
            visited[v] = True

            traverse(v, counter + 1, c_current + c[u][v])

            # quay lui
            visited[v] = False
   

def process():
    global n, visited

    visited = [False] * (n + 1)

    # Thử xuất phát từ mọi địa điểm
    for u in range(1, n + 1):
        visited[u] = True

        # Xuất phát từ điểm u, số điểm đã ghé thăm là 1, tổng chi phí là 0
        traverse(u, 1, 0)

        visited[u] = False
    

def output():
    global result

    sys.stdout = open(output_file, 'w')
    
    print(result)


if __name__ == '__main__':
    input()
    process()
    output()