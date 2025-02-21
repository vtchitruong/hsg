import os
import sys

input_file = os.path.join(sys.path[0], 'ddnt.inp')
output_file = os.path.join(sys.path[0], 'ddnt.out')

n = m = start = finish = 0
graph = []

# D[u] là khoảng cách ngắn nhất từ đỉnh start đến đỉnh u
D = []

# Sàng nguyên tố
prime = []


def input_data():
    global n, m, start, finish, graph

    with open(input_file, 'r') as f:
        n, m, start, finish = map(int, f.readline().split())

        graph = [[] for _ in range(n + 1)]

        for i in range(m):
            u, v, w = list(map(int, f.readline().split()))
            graph[u].append((v, w))
            graph[v].append((u, w))


# Hàm dùng để tạo sàng nguyên tố trong phạm vi đến 1 triệu lẻ 3
def sieve():
    global prime

    number = 1000003

    # Giả sử mọi số đều nguyên tố
    prime = [True] * number

    # 0 và 1 không phải số nguyên tố
    prime[0] = prime[1] = False

    # Duyệt từ 2 đến căn bậc 2 của number
    for p in range(2, int(number ** 0.5) + 1):
        # Nếu p là số nguyên tố thì đánh dấu false cho các bội của p
        if prime[p]:
            for i in range(p * p, number + 1, p):
                prime[i] = False


# Hàm dùng để tính giá trị tăng thêm để đạt được số nguyên tố tiếp theo lớn hơn w
def increase_to_next_prime(w):
    global prime

    # Nếu w là số nguyên tố thì trả về 0
    if prime[w]:
        return 0

    # Tìm số nguyên tố tiếp theo lớn hơn w
    next_prime = w + 1
    while prime[next_prime] == False:
        next_prime += 1
    
    return next_prime - w


def dijkstra():
    global n, start, graph, D, prime

    # Mảng D dùng để lưu trữ khoảng cách từ đỉnh start đến các đỉnh còn lại
    D = [float('inf')] * (n + 1)
    D[start] = 0

    # Mỗi phần tử trong set là {d, u}, trong đó d là khoảng cách ngắn nhất từ start đến u
    q = []
    q.append((0, start))

    # Trong khi q vẫn còn phần tử
    while q:
        # Lấy ra đỉnh u có khoảng cách ngắn nhất từ start
        min_element = min(q, key=lambda x: x[0])
        d = min_element[0]
        u = min_element[1]
        q.remove(min_element)

        # Dừng khi đã đến đỉnh finish
        if u == finish:
            break

        # Nếu đã có một đường đi ngắn hơn từ start đến u thì không cần xét đỉnh u nữa
        if d > D[u]:
            continue

        # Duyệt từng đỉnh v kề với đỉnh u
        for i in range(len(graph[u])):
            
            # v là đỉnh kề với u
            v = graph[u][i][0]

            # w là trọng số của cạnh u -> v
            w = graph[u][i][1]

            # Tìm giá trị tăng thêm để đạt được số nguyên tố tiếp theo lớn hơn w
            increase = increase_to_next_prime(w)

            # Nếu có thể đi start -> u -> v nhanh hơn so với start -> v
            if D[u] + increase < D[v]:
                # Nếu v đã có trong hàng đợi thì xoá phần tử liên quan
                if (D[v], v) in q:
                    q.remove((D[v], v))

                # Cập nhật lại khoảng cách ngắn nhất từ đỉnh start đến đỉnh v
                D[v] = D[u] + increase

                # Thêm v vào q với khoảng cách ngắn nhất từ start đến v là D[v]
                q.append((D[v], v))


def output():
    global D, finish

    with open(output_file, 'w') as f:
        f.write(str(D[finish]))


if __name__ == "__main__":
    input_data()
    sieve()
    dijkstra()
    output()
