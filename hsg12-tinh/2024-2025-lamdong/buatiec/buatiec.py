import os
import sys

input_file = os.path.join(sys.path[0], 'buatiec.inp')
output_file = os.path.join(sys.path[0], 'buatiec.out')

n = 0
H = []

# Danh sách kề
adj = dict()

# Mảng D dùng để lưu tổng độ vui vẻ
# D[l][0] là tổng độ vui vẻ lớn nhất nếu l không được chọn
# D[l][1] là tổng độ vui vẻ lớn nhất nếu l được chọn
D = []


def input_data():
    global n, H, adj

    with open(input_file, 'r') as file:
        n = int(file.readline().strip())
        H = list(map(int, file.readline().split()))

        # Thêm 0 vào đầu H để phù hợp với chỉ số của node
        H.insert(0, 0)

        for i in range(n - 1):
            l, k = map(int, file.readline().split())
            if k not in adj:
                adj[k] = []
            adj[k].append(l)


# Hàm dùng để duyệt cây theo chiều sâu
def dfs(k):
    global D, H

    # Khởi tạo khi chọn node k
    D[k][1] = H[k]

    # Duyệt từng con của node k
    for l in adj.get(k, []):
        # Gọi đệ quy
        dfs(l)

        # Nếu chọn k thì không thể chọn con của k
        D[k][1] += D[l][0]

        # Nếu không chọn k thì có thể chọn hoặc không chọn con của k
        D[k][0] += max(D[l][0], D[l][1])


def process():
    global D

    # Khởi tạo D gồm n+1 hàng và 2 cột
    D = [[0, 0] for _ in range(n + 1)]

    # Gọi hàm dfs từ node 1 (giám đốc)
    dfs(1)

    # Tổng độ vui vẻ lớn nhất
    result = D[1][1]

    with open(output_file, 'w') as file:
        file.write(str(result))


if __name__ == '__main__':
    input_data()
    process()