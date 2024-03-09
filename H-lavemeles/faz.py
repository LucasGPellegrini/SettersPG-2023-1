from math import factorial
from random import random


def goalies(n, m):
    return int(factorial(n+m) / (factorial(m) * factorial(n)))


reps = {}

for i in range(1, 20 + 1):
    i_name = f'{i:03d}'
    n = int(random() * 7)
    m = int(random() * 7)

    while str([n, m]) in reps:
        n = int(random() * 7)
        m = int(random() * 7)

    with open(f'input/{i_name}', 'w') as f:
        f.write(f'{n} {m}\n')
    with open(f'output/{i_name}', 'w') as f:
        f.write(f'{goalies(n, m)}\n')
