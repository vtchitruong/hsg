from pathlib import Path

dir = Path(__file__).parent
input_file = dir / 'tree.inp'
output_file = dir / 'tree.out'

MAX = 100002 

# nhãn của khu nút mới
n = 0

# parent[i] là cha của nút i
parent = [0] * MAX

# children[i] là vector lưu các con trực tiếp của i
children = [[] for _ in range(MAX)]

# tree_size[i] là số lượng nút trong cây con có gốc là i, bao gồm cả i
tree_size = [0] * MAX


# Hàm thêm nút con của nút u
def add(u):
    global n, parent, children, tree_size

    # Nút mới có nhãn là n
    new_node = n

    # Thiết lập liên kết cha và con đối với nút mới
    parent[new_node] = u
    children[u].append(new_node)

    # Khởi tạo kích thước cho nút mới
    tree_size[new_node] = 1

    # Cập nhật kích thước cây con của các nút tổ tiên
    # bằng cách duyệt ngược từ u về gốc
    current = u
    while current != -1:    
        tree_size[current] += 1
        current = parent[current]
    
    # Tăng nhãn cho nút tiếp theo
    n += 1


# Hàm xoá nút u và hệ thống con cuả u
def remove(u):
    global n, parent, children, tree_size

    # nút cha của nút u
    p = parent[u]
    
    # kích thước của hệ thống con của u
    size_u = tree_size[u]

    if p != -1:
        children[p].remove(u)
        
    # Cập nhật kích thước cây con của các nút tổ tiên
    # bằng cách duyệt ngược từ p về gốc
    current = p
    while current != -1:
        tree_size[current] -= size_u
        current = parent[current]
    

# Hàm lấy kích thước hệ thống con của u, gồm cả u
def get_size(u):
    global tree_size

    return tree_size[u]


def input_process():
    global n, parent, tree_size

    with open(input_file, 'r') as fi, open(output_file, 'w') as fo:
        # Khởi tạo nút 0
        parent[0] = -1
        tree_size[0] = 1
        
        # nhãn của nút tiếp theo sẽ là 1
        n = 1

        # Đọc số truy vấn
        number_of_queries = int(fi.readline()) 

        # Duyệt từng truy vấn q
        for q in range(number_of_queries):
            task, u = fi.readline().split()
            u = int(u)

            if task == '+':
                add(u)
            elif task == '-':
                remove(u)
            else:
                fo.write(f'{get_size(u)}\n')


if __name__ == '__main__':
    input_process()