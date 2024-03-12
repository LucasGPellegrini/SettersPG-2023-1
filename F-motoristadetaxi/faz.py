from math import factorial
from random import random


def gera_numero(a, b, pode_negativo=False):
    return int((a + random() * (b - a)) * (1 if not pode_negativo else (1 if random() < 0.5 else -1)))


def gera_teste():
    n = int(random() * 4_999)
    inp = f'{n}\n'
    for _ in range(n):
        inp += f'{gera_numero(-(2 ** 16), 2 ** 16, True)} {gera_numero(-(2 ** 16), 2**16, True)}\n'
    return inp


def resolve(teste):
    linhas = teste.strip().split('\n')
    n = int(linhas[0])
    linhas = linhas[1:]
    dist = 0
    last_x, last_y = 0, 0
    for linha in linhas:
        x, y = map(int, linha.split())
        dist += abs(x - last_x) + abs(y - last_y)
        last_x, last_y = x, y
    return f'{dist}\n'


reps = {}

for i in range(1, 20 + 1):
    i_name = f'{i:03d}'

    teste = gera_teste()
    while teste in reps:
        teste = gera_teste()

    with open(f'input/{i_name}', 'w') as f:
        f.write(teste)
    with open(f'output/{i_name}', 'w') as f:
        f.write(f'{resolve(teste)}')
