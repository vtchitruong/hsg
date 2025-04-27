import os
import sys

input_file = os.path.join(sys.path[0], 'trochoi.inp')
output_file = os.path.join(sys.path[0], 'trochoi.out')

# biến m và n
number_of_questions = number_of_teams = 0

# mảng lưu điểm số
a = []

# total[i] là tổng điểm của đội i
total = []

# điểm số cao nhất
max_score = 0

# đội có điểm số cao nhất
max_team = 0


def input():
    global number_of_questions, number_of_teams, total

    with open(input_file, 'r') as f:
        number_of_questions, number_of_teams = map(int, f.readline().split())

        # Khởi tạo mảng lưu tổng điểm của mỗi đội
        total = [0] * number_of_teams

        # Duyệt từng câu hỏi (từng hàng)
        for q in range(number_of_questions):
            line = f.readline().split()

            # Duyệt từng đội (từng cột)
            for t in range(number_of_teams):
                score = int(line[t])

                # Cộng dồn điểm cho từng đội
                total[t] += score


def process():
    global number_of_teams, total, max_score, max_team

    # Duyệt từng điểm tổng trong mảng total
    for i in range(number_of_teams):   
        if total[i] > max_score:        
            # Cập nhật tổng điểm cao nhất
            max_score = total[i]

            # Ghi nhận mã số của đội có điểm cao nhất
            max_team = i + 1


def output():
    with open(output_file, 'w') as f:
        f.write(f'{max_team} {max_score}')


if __name__ == '__main__':
    input()
    process()
    output()
