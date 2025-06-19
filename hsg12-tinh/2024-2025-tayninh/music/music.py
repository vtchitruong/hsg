from pathlib import Path

dir = Path(__file__).parent
input_file = dir / 'music.inp'
output_file = dir / 'music.out'

n = 0
A = []

# mảng tổng tiền tố prefix_sum
# ps[i] là tổng các phần tử trong đoạn [0..i - 1]
ps = []

# độ hấp dẫn lớn nhất cần tìm
max_attractive = max_attractive = float('-inf')


def input():
    global n, A

    with open(input_file, 'r') as f:
        n = int(f.readline())

        A = list(map(int, f.readline().split()))


def process():
    global n, A, ps, max_attractive

    # Tính mảng tổng tiền tố
    ps = [0] * (n + 1)

    for i in range(n):
        ps[i + 1] = ps[i] + A[i]

    # min_ps_even Lưu giá trị ps[i - 1] nhỏ nhất, với i - 1 là chẵn.
    # i - 1 = 0 là chẵn, ps[0] = 0
    min_ps_even = ps[0]

    # min_ps_odd lưu giá trị ps[i - 1] nhỏ nhất, với i - 1 là lẻ.
    min_ps_odd = float('inf')

    # Duyệt mảng tổng tiền tố trong đoạn [4..n]
    for right in range(n + 1):
        k = right - 4

        # Cập nhật giá trị min_ps_even và min_ps_odd
        if k % 2 == 0:
            min_ps_even = min(min_ps_even, ps[k])
        else:
            min_ps_odd = min(min_ps_odd, ps[k])

        # Tính độ hấp dẫn lớn nhất
        if right % 2 == 0:
            max_attractive = max(max_attractive, ps[right] - min_ps_even)
        else:
            if min_ps_odd != float('inf'):
                max_attractive = max(max_attractive, ps[right] - min_ps_odd)


def output():
    global max_attractive

    with open(output_file, 'w') as f:
        f.write(f'{max_attractive}')


if __name__ == '__main__':
    input()
    process()
    output()