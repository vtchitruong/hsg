import os
import sys
import math

input_file = os.path.join(sys.path[0], 'sodacbiet.inp')
output_file = os.path.join(sys.path[0], 'sodacbiet.out')

a = b =0
number_of_special_numbers = 0


def input():
    global a, b

    with open(input_file, 'r') as f:
        a, b = map(int, f.readline().split())


# Hàm dùng để kiểm tra đối xứng
def is_palindrome(n):
    # Số có một chữ số thì luôn đối xứng
    if n < 10:
        return True

    # Số có hàng đơn vị là 0 thì không đối xứng
    if n % 10 == 0:
        return False
    
    # biến lưu số ban đầu và số đảo ngược
    original = n
    reversed = 0

    while n > 0:
        # Lấy ra chữ số hàng đơn vị
        digit = n % 10

        # Ghép vào đầu của số đảo ngược
        reversed = reversed * 10 + digit

        n //= 10

    return original == reversed


# Hàm đếm số lượng ước nguyên tố khác nhau của number
def count_prime(number):
    if number == 1:
        return 0

    # biến lưu các thừa số nguyên tố khác nhau
    factors = set()

    n = number

    # Kiểm tra 2 có phải là ước không
    if n % 2 == 0:
        factors.add(2)

        while n % 2 == 0:
            n //= 2

    # Kiểm tra các ước số lẻ từ 3 trở đi
    for i in range(3, int(math.sqrt(n)) + 1):
        if n % i == 0:
            factors.add(i)

            while n % i == 0:
                n //= i

    # Sau khi chia, nếu n vẫn lớn hơn 2 thì n là một ước nguyên tố
    if n > 2:
        factors.add(n)

    return len(factors)


def process():
    global a, b, number_of_special_numbers

    # Duyệt từng số từ a đến b
    for i in range(a, b + 1):
        if is_palindrome(i):
            if count_prime(i) >= 3:
                number_of_special_numbers += i


def output():
    global number_of_special_numbers

    with open(output_file, 'w') as f:
        f.write(str(number_of_special_numbers))


if __name__ == '__main__':
    input()
    process()
    output()