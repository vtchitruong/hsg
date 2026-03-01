import os
import sys

input_file = os.path.join(sys.path[0], 'doanqc.inp')
output_file = os.path.join(sys.path[0], 'doanqc.out')

n = 0

# mỗi phần tử là một cặp số cho biết thời điểm vào và ra {checkin, checkout}
customers = []

# mảng lưu các thời điểm phát quảng cáo
schedule = []


def input():
    global n, customers

    sys.stdin = open(input_file, 'r')

    # Đọc toàn bộ dữ liệu vào bộ nhớ đệm và tách thành các token
    data = sys.stdin.read().split()

    iterator = iter(data)

    n = int(next(iterator))

    customers = [(0, 0)] * n 

    for i in range(n):
        checkin = int(next(iterator))
        checkout = int(next(iterator))
        
        customers[i] = (checkin, checkout)


def process():
    global customers
    
    # Lấy thời điểm vào của khách hàng đầu tiên
    min_checkin = min(customers, key=lambda t: t[0])[0]

    # Lưu thời điểm vào nhỏ nhất vào lịch
    schedule.append(min_checkin)

    # Sắp xếp khách hàng theo thứ tự tăng dần của thời điểm ra
    customers.sort(key=lambda t: t[1])

    # biến latest_ad lưu thời điểm mới nhất phát quảng cáo
    latest_ad = -1

    # Duyệt từng khách hàng trong mảng customers đã sắp xếp
    for c in customers:
        # Nếu thời điểm vào xảy ra sau thời điểm phát quảng cáo mới nhất
        if latest_ad <= c[0]:
            # thì phát quảng cáo tại thời điểm ra
            schedule.append(c[1])

            # Ghi nhận thời điểm phát quảng cáo mới nhất
            latest_ad = c[1]


def output():
    sys.stdout = open(output_file, 'w')

    print(len(schedule))
    print(*schedule)


if __name__ == '__main__':
    input()
    process()
    output()