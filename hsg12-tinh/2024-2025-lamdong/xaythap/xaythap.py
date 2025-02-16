import os
import sys

input_file = os.path.join(sys.path[0], 'xaythap.inp')
output_file = os.path.join(sys.path[0], 'xaythap.out')


class gift:
    def __init__(self, r, color):
        self.r = r
        self.color = color

n = 0
G = []

# Biến D dùng để lưu tổng số hộp quà
# D[i][c] là tổng số hộp quà nhiều nhất, trong đó hộp quà có chỉ số i nằm trên cùng và có màu c
D = []

max_gift = 0

def input_data():
    global n, G

    with open(input_file, 'r') as f:
        n = int(f.readline().strip())
        
        G = [gift(0, 0) for _ in range(n)]

        X = list(map(int, f.readline().split()))

        for i in range(n):
            G[i].r = abs(X[i])
            G[i].color = 1 if X[i] > 0 else 0


def process():
    global n, G, D, max_gift

    # Sắp xếp hộp quà theo thứ tự độ rộng giảm dần
    G.sort(key=lambda x: x.r, reverse=True)

    # Khởi tạo mảng D với n phần tử
    D = [[0] * 2 for _ in range(n)]

    # Duyệt từng hộp quà i
    for i in range(n):
        # Màu của hộp quà i
        color_of_i = G[i].color

        # Nếu chọn hộp quà i thì số hộp quà nhiều nhất tại vị trí i là 1
        D[i][color_of_i] = 1

        # Duyệt từng hộp quà j trước đó
        for j in range(i):
            # Nếu hộp quà j có màu khác với hộp quà i và hộp quà j có độ rộng nhỏ hơn hộp quà i
            if G[i].r < G[j].r:
                if G[j].color != color_of_i:
                    # thì cập nhật số hộp quà nhiều nhất tại vị trí i
                    D[i][color_of_i] = max(D[i][color_of_i], D[j][1 - color_of_i] + 1)

        # Nếu số hộp quà nhiều nhất tại vị trí i lớn hơn max_gift thì cập nhật max_gift
        max_gift = max(max_gift, D[i][color_of_i])


def output():
    global max_gift
    with open(output_file, 'w') as f:
        f.write(str(max_gift))


if __name__ == '__main__':
    input_data()
    process()
    output()