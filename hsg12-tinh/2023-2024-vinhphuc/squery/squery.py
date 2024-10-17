import os
import sys

input_file = os.path.join(sys.path[0], 'squery.inp')
output_file = os.path.join(sys.path[0], 'squery.out')

n, q = 0, 0
A = []
result = []

# Hàm dùng để đếm số phần tử là ước hoặc bội của d
def count_dm(l, r, d):
    cnt = 0
    
    # Duyệt mảng A từ vị trí l đến vị trí r
    for i in range(l, r + 1):
        # Xét A[i] là ước hoặc bội của d
        if A[i] % d == 0 or d % A[i] == 0:
            cnt += 1
    return cnt


def input_data():
    global n, q, A, result

    with open(input_file, 'r') as f:
        n, q = map(int, f.readline().split())

        # Cấp phát bộ nhớ cho n + 1 phần tử (vì mảng A đánh chỉ số từ 1)
        A = [0] * (n + 1)

        A[1:] = list(map(int, f.readline().split()))

        # Gọi hàm count_dm để đếm ước và bội
        for _ in range(q):
            l, r, d = map(int, f.readline().split())
            cnt = count_dm(l, r, d)
            result.append(cnt)


def output():
    with open(output_file, 'w') as f:
        f.write(' '.join(map(str, result)))


if __name__ == '__main__':
    input_data()
    output()
