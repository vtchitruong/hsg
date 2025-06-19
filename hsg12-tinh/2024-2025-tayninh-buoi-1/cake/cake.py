from pathlib import Path
from collections import deque

dir = Path(__file__).parent
input_file = dir / 'cake.inp'
output_file = dir / 'cake.out'

# hằng số âm vô cực
INF = float('-inf')

n = m = k = 0
A = []

# điểm thưởng cao nhất cần tìm
max_score = 0


def input():
    global n, m , k, A

    with open(input_file, 'r') as f:
        n, m, k = map(int, f.readline().split())

        A = [0] + list(map(int, f.readline().split()))


def process():
    global n, m, k, A, max_score

    # Khởi tạo bảng quy hoạch động gồm k + 1 lượt chọn (hàng)
    # Mỗi hàng gồm n + 1 điểm thưởng cao nhất (cột)
    # D[choice][cake] là điểm thưởng cao nhất sau choice lượt chọn, kết thúc ở bánh thứ cake
    D = [[INF]  * (n + 1) for _ in range(k + 1)]

    # Khởi tạo lượt chọn 1 (hàng 1)
    for cake in range(1, n + 1):
        D[1][cake] = A[cake]

    # Điền bảng quy hoạch động từ lượt (hàng) 2 đến k
    # Duyệt từng lượt chọn (hàng)
    for choice in range(2, k + 1):
        # Khai báo hàng đợi hai đầu lưu chỉ số cake của lượt choice - 1
        Q = deque()

        # Duyệt từng bánh (cột)
        for cake in range(1, n + 1):
            if D[choice - 1][cake - 1] != INF:
                # Loại bỏ các D[][] nhỏ hơn ở cuối hàng đợi (tức bên phải)
                while Q and D[choice - 1][Q[-1]] <= D[choice - 1][cake - 1]:
                    Q.pop()

                # Nạp cake - 1 vào cuối hàng đợi
                Q.append(cake - 1)

            # Loại bỏ chỉ số ở đầu hàng đợi Q vì nó nằm ngoài cửa sổ [cake - m, cake - 1]
            if Q and Q[0] < cake - m:
                Q.popleft()

            # Tính D[choice][cake]
            if Q:
                if D[choice - 1][Q[0]] != INF:
                    D[choice][cake] = D[choice - 1][Q[0]] + choice * A[cake]

    # Duyệt các điểm cao nhất trong lượt k (hàng k) để lấy ra kết quả cao nhất
    max_score = max(D[k])


def output():
    global max_score

    with open(output_file, 'w') as f:
        f.write(f'{max_score}')


if __name__ == '__main__':
    input()
    process()
    output()
