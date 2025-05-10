import os
import sys
import math

input_file = os.path.join(sys.path[0], 'songuyento.inp')
output_file = os.path.join(sys.path[0], 'songuyento.out')

n = result = 0


def input():
    global n

    with open(input_file, 'r') as f:
        n = int(f.readline())


def is_prime(x):
    if x < 2:
        return False
    
    if x < 4:
        return True

    if x % 2 == 0 or x % 3 == 0:
        return False
    
    for i in range(5, int(math.sqrt(x)) + 1, 6):
        if x % i == 0 or x % (i + 2) == 0:
            return False
        
    return True


def process():
    global n, result

    while True:
        if is_prime(n):
            result = n
            break
    
        n += 1


def output():
    global result

    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input()
    process()
    output()