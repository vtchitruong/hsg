import os
import sys

input_file = os.path.join(sys.path[0], 'chiphi.inp')
output_file = os.path.join(sys.path[0], 'chiphi.out')

INF = int(1e18)

class node:
    def __init__(self, id, travel_cost):
        self.id = id
        self.travel_cost = travel_cost

# số nút, số nút, số truy vấn
n = m = r = 0

# Mảng lưu nút và chi phí hành trình T
T = []

# Mảng lưu nút và chi phí hành trình T để tìm giá trị lớn nhất
nodes = []

# Mảng lưu chi phí lưu thông L giữa hai nút
L = []

# Mảng lưu các truy vấn (là các cặp nút)
queries = []

# mảng lưu kết quả tổng chi phí nhỏ nhất giữa hai cặp nút (dành cho các truy vấn)
results = []


def input_data():
    global n, m, r, T, L, nodes, queries, results

    with open(input_file, 'r') as f:
        n, m, r = map(int, f.readline().split())

        # Đọc chi phí hành trình T
        T = [0] * (n + 1)
        nodes = [node(0, 0) for _ in range(n)]

        for i in range(n):
            nodes[i].id = i + 1
            nodes[i].travel_cost = int(f.readline())
            T[i + 1] = nodes[i].travel_cost

        # Khởi tạo mảng chi phí lưu thông L
        L = [[INF for _ in range(n + 1)] for _ in range(n + 1)]

        # Khởi tạo mảng kết quả
        results = [[INF for _ in range(n + 1)] for _ in range(n + 1)]

        # Khởi tạo cho trường hợp một nút đi đến chính nó
        for i in range(1, n + 1):
            L[i][i] = 0
            results[i][i] = T[i]

        # Đọc chi phí lưu thông l giữa hai nút i và k
        for u in range(m):
            i, k, l = map(int, f.readline().split())

            L[i][k] = l
            L[k][i] = l

            # Tạm tính tổng chi phí ban đầu 
            initial_total_cost = l + max(T[i], T[k])
            results[i][k] = initial_total_cost
            results[k][i] = initial_total_cost

        # Khởi tạo mảng các truy vấn
        queries = [(0, 0)] * r

        # Đọc các cặp nút cần truy vấn
        for i in range(r):
            u_query, v_query = map(int, f.readline().split())
            queries[i] = (u_query, v_query)


def process():
    global n, m, r, T, L, nodes, queries, results

    # Sắp xếp các nút theo chi phí hành trình tăng dần
    nodes.sort(key=lambda node: node.travel_cost)

    # nút trung gian k và phí hành trình t tại nút k 
    k = tk = 0

    # Duyệt từng nút theo thứ tự vừa sắp xếp ở trên
    for p in range(n):
        # Xét nút trung gian k và chi phí hành trình tại k
        k = nodes[p].id
        tk = nodes[p].travel_cost

        # Duyệt từng cặp nút u - v
        for u in range(1, n + 1):
            for v in range(1, n + 1):
                # 1. Tính chi phí lưu thông khi đi qua nút trung gian k
                if L[u][k] != INF and L[k][v] != INF:
                    L[u][v] = min(L[u][v], L[u][k] + L[k][v])
                
                # 2. Tính tổng chi phí kết quả tốt nhất (nếu có đường đi từ u đến v)
                if L[u][v] != INF:
                    results[u][v] = min(results[u][v], L[u][v] + max(T[u], T[v], T[k]))
                
            # Bảo đảm tính đối xứng cho mảng results sau mỗi bước k
            for u in range(1, n + 1):
                for v in range(1, n + 1):
                    results[u][v] = min(results[u][v], results[v][u])
                    results[v][u] = results[u][v]


def output():
    global queries, results

    with open(output_file, 'w') as f:
        for i in range(r):
            u = queries[i][0];
            v = queries[i][1];

            f.write(str(results[u][v]) + '\n')


if __name__ == '__main__':
    input_data()
    process()
    output()
        
    