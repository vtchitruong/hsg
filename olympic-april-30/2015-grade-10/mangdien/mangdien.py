import os
import sys

input_file = os.path.join(sys.path[0], 'mangdien.inp')
output_file = os.path.join(sys.path[0], 'mangdien.out')

# Cấu trúc edge biểu thị kết nối giữa hai công ty
class edge:
    def __init__(self, a, b, cost):
        self.a = a
        self.b = b
        self.cost = cost


    def __lt__(self, other):
        return self.cost < other.cost
    

    def __eq__(self, other):
        return self.a == other.a and self.b == other.b and self.cost == other.cost


n = 0
m = 0

# Mảng các kết nối
edges = []

# rep[a] là đại diện của tập hợp chứa công ty a
# ranking[a] là độ sâu của cây tập hợp chứa công ty a
rep = []
ranking = []

s1 = 0
s2 = 0

def input_data():
    global n, m, edges

    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().split())

        edges = [edge(*map(int, f.readline().split())) for _ in range(m)]


# Hàm tìm đại diện của tập hợp chứa công ty a
def find(a):
    global rep

    if a != rep[a]:
        rep[a] = find(rep[a])

    return rep[a]


# Hàm hợp nhất hai tập hợp chứa công ty a và b
def unite(a, b):
    global rep, ranking

    # Lấy đại diện của hai tập hợp chứa a và b
    rep_a = find(a)
    rep_b = find(b)

    # Nếu a và b cùng một tập hợp thì không làm gì cả
    if rep_a == rep_b:
        return False
    
    # Ngược lại, nếu không cùng tập hợp thì hợp nhất hai tập hợp
    if ranking[rep_a] > ranking[rep_b]:
        rep[rep_b] = rep_a
    elif ranking[rep_a] < ranking[rep_b]:
        rep[rep_a] = rep_b
    else:
        rep[rep_b] = rep_a
        ranking[rep_a] += 1

    return True


# Hàm tìm cây khung nhỏ nhất
def kruskal(excluded_edges, included_edges):
    global n, edges, rep, ranking

    # Khởi tạo mảng rep và ranking
    rep = list(range(n + 1))
    ranking = [0] * (n + 1)

    total_cost = 0

    # Duyệt từng kết nối trong input
    for e in edges:
        # Nếu kết nối đang xét nằm trong mảng loại trừ thì bỏ qua
        if e in excluded_edges:
            continue
        
        # Ngược lại, nếu kết nối đang xét không nằm trong mảng loại trừ
        if unite(e.a, e.b) == True:
            # thì cộng dồn tổng chi phí
            total_cost += e.cost

            # và thêm vào mảng cây khung nhỏ nhất
            included_edges.append(e)

    # Nếu không đủ n - 1 cạnh thì trả về -1
    if len(included_edges) != n - 1:
        return -1
    
    return total_cost
        

# Hàm xử lý bài toán
def process():
    global edges, s1, s2

    # Sắp xếp các kết nối theo chi phí tăng dần
    edges.sort()

    excluded_edges = []
    included_edges = []

    # Tìm s1
    s1 = kruskal(excluded_edges, included_edges)

    # Tìm s2
    s2 = float('inf')

    for e in included_edges:
        # Thử loại bỏ kết nối e
        excluded_edges.append(e)

        # Mảng lưu cây khung nhỏ nhất mới
        tmp_included_edges = []

        # Tính chi phí của cây khung nhỏ nhất mới
        cost = kruskal(excluded_edges, tmp_included_edges)

        # Xét xem chi phí mới có phải là nhỏ thứ nhì hay không
        if cost != -1 and cost >= s1:
            s2 = min(s2, cost)

        # Đưa kết nối e trở lại
        excluded_edges.pop()

    if s2 == float('inf'):
        s2 = s1


def output():
    global s1, s2

    with open(output_file, 'w') as f:
        f.write(f'{s1} {s2}')


if __name__ == '__main__':
    input_data()
    process()
    output()