import os
import sys

input_file = os.path.join(sys.path[0], 'xplore.inp')
output_file = os.path.join(sys.path[0], 'xplore.out')

INF = float('inf')

T = N = 0

positives = [] # mảng lưu các địa điểm dương
negatives = [] # mảng lưu các địa điểm âm

# số điểm ghé thăm
visited_count = 0


def input():
    global T, N

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    T = int(next(iterator))
    N = int(next(iterator))

    for i in range(N):
        x = int(next(iterator))

        if x < 0:        
            negatives.append(x)
        elif x > 0:        
            positives.append(x)
        else:
            # Nếu 0 là địa điểm thì nó được tính là ghé thâm ngay khi xuất phát
            visited_count += 1


def process():
    global visited_count

    # Sắp xếp mảng địa điểm dương tăng dần
    positives.sort()

    # Sắp xếp mảng địa điểm âm giảm dần
    negatives.sort(reverse=True)

    # biến lưu địa điểm hiện đang ghé thăm
    current = 0

    # biến lưu thời gian trôi qua
    elapsed_time = 0

    # hai con trỏ dành cho hai mảng dương và âm
    p = 0
    n = 0

    # Duyệt từng điểm trong hai mảng dương và âm
    while p < len(positives) or n < len(negatives):
        # Tính khoảng cách từ current đến hai điểm dương và âm
        p_distance = abs(positives[p] - current) if p < len(positives) else INF
        n_distance = abs(negatives[n] - current) if n < len(negatives) else INF

        # Chọn khoảng cách nhỏ hơn
        if n_distance <= p_distance:        
            if elapsed_time + n_distance > T:
                break

            elapsed_time += n_distance
            current = negatives[n]
            n += 1        
        else:        
            if elapsed_time + p_distance > T:
                break

            elapsed_time += p_distance
            current = positives[p]
            p += 1
        
        # Cập nhật số địa điểm ghé thăm
        visited_count += 1
    

def output():
    sys.stdout = open(output_file, 'w')

    print(visited_count)


if __name__ == '__main__':
    input()
    process()
    output()