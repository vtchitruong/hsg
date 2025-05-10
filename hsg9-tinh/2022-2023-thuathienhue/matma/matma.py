import os
import sys

input_file = os.path.join(sys.path[0], 'matma.inp')
output_file = os.path.join(sys.path[0], 'matma.out')

mom_day = mom_month = mom_year = 0
dad_day = dad_month = dad_year = 0

# mật mã cần tìm
code = 0


def input():
    global mom_day, mom_month, mom_year, dad_day, dad_month, dad_year

    with open(input_file, 'r') as f:
        mom_day, mom_month, mom_year = map(int, f.readline().split())
        dad_day, dad_month, dad_year = map(int, f.readline().split())


# Hàm tìm ước chung lớn nhất
def gcd(a, b):
    while b > 0:
        a, b = b, a % b

    return a


def process():
    global mom_day, mom_month, mom_year, dad_day, dad_month, dad_year, code

    mom_sum = mom_day + mom_month + mom_year

    dad_sum = dad_day + dad_month + dad_year

    g = gcd(mom_sum, dad_sum)

    code = mom_sum // g * dad_sum


def output():
    global code

    with open(output_file, 'w') as f:
        f.write(str(code))


if __name__ == '__main__':
    input()
    process()
    output()