import os
import sys

input_file = os.path.join(sys.path[0], 'trochoi.inp')
output_file = os.path.join(sys.path[0], 'trochoi.out')

# biến m và n
number_of_questions = number_of_teams = 0

# total[i] là tổng điểm của đội i
total = []

# điểm số cao nhất
max_score = -1

# đội có điểm số cao nhất
max_team = -1


def input():
    global number_of_questions, number_of_teams, total

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    number_of_questions = int(next(iterator))
    number_of_teams = int(next(iterator))

    # Khởi tạo mảng lưu tổng điểm của mỗi đội
    total = [0] * number_of_teams

    # Duyệt từng câu hỏi (từng hàng)
    for q in range(number_of_questions):
        # Duyệt từng đội (từng cột)
        for t in range(number_of_teams):
            score = int(next(iterator))

            # Cộng dồn điểm cho từng đội
            total[t] += score


def process():
    global number_of_teams, total, max_score, max_team

    # Duyệt từng điểm tổng trong mảng total
    for i, score in enumerate(total):   
        if score > max_score:        
            # Cập nhật tổng điểm cao nhất
            max_score = score

            # Cập nhật mã số của đội có điểm cao nhất
            max_team = i + 1


def output():
    global max_score, max_team

    sys.stdout = open(output_file, 'w')

    print(f'{max_team} {max_score}')


if __name__ == '__main__':
    input()
    process()
    output()
