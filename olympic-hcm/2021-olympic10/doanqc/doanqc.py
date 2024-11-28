import os
import sys

input_file = os.path.join(sys.path[0], 'doanqc.inp')
output_file = os.path.join(sys.path[0], 'doanqc.out')

n = 0

# Mỗi phần tử là một cặp số cho biết thời điểm vào và ra [check_in, check_out]
customers = []

# Mảng lưu lịch phân bố thời điểm phát quảng cáo 
ad_schedule = []


def input_data():
    with open(input_file, 'r') as f:
        global n, customers

        n = int(f.readline())

        for i in range(n):
            check_in, check_out = map(int, f.readline().split())
            customers.append((check_in, check_out))


def process():
    global customers
    
    # Lấy thời điểm vào của khách hàng đầu tiên
    first_check_in = min(customers, key=lambda t: t[0])[0]

    # Lưu thời điểm vào nhỏ nhất vào lịch phân bố
    ad_schedule.append(first_check_in)

    # Sắp xếp khách hàng theo thứ tự tăng dần của thời điểm ra
    customers.sort(key=lambda t: t[1])

    # Biến latest_ad lưu thời điểm mới nhất phát quảng cáo
    latest_ad = -1

    # Duyệt từng khách hàng trong mảng customers đã sắp xếp
    for customer in customers:    
        # Lấy thời điểm vào và thời điểm ra
        check_in = customer[0]
        check_out = customer[1]

        # Nếu thời điểm vào xảy ra sau thời điểm phát quảng cáo mới nhất
        if latest_ad <= check_in:
            # thì phát quảng cáo tại thời điểm ra
            ad_schedule.append(check_out)

            # Ghi nhận thời điểm phát quảng cáo mới nhất
            latest_ad = check_out


def output():
    global ad_schedule
    with open(output_file, 'w') as f:
        f.write(str(len(ad_schedule)))
        f.write('\n')
        f.write(' '.join(map(str, ad_schedule)))


if __name__ == '__main__':
    input_data()
    process()
    output()