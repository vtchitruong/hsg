import os
import sys

input_file = os.path.join(sys.path[0], 'xephang.inp')
output_file = os.path.join(sys.path[0], 'xephang.out')

n = m = 0
T = []
R = []


class team:
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b

    # Hàm dùng để so sánh đội T[1] với đội khác
    # Trả về True nếu đội khác tốt hơn
    def is_another_team_better(self, another):
        if self.a < another.a or (self.a == another.a and self.b > another.b):
            return True
        return False

    # Hàm dùng để xếp hạng đội T[1]
    def process(self):
        global T, R

        # Khởi tạo đội T[1] hạng nhất
        rank = 1

        # Duyệt từng đội từ 1 đến n
        for i in range(1, n + 1):
            # Nếu đội T[i] nào đó tốt hơn đội T[1] thì tăng hạng đội T[1]
            if self != 1 and self.is_another_team_better(T[i]):
                rank += 1

        return rank


def input_data():
    global n, m, T, R

    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().split())

        # Khởi tạo mảng T chứa dữ liệu của n đội
        T = [team(0, 0) for _ in range(n + 1)]

        # Duyệt từng lượt nộp bài
        for _ in range(m):
            # Đọc mã đội và điểm phạt
            team_id, penalty = map(int, f.readline().split())
            
            # Ghi nhận điểm số và điểm phạt của đội team_id
            T[team_id].a += 1
            T[team_id].b += penalty

            # Xếp hạng cho đội T[1]
            r = T[1].process()
            R.append(r)


def output():
    with open(output_file, 'w') as f:
        f.writelines(f'{r}\n' for r in R)


if __name__ == '__main__':
    input_data()
    output()
    