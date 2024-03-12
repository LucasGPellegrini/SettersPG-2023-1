from math import factorial
from random import random


def gera_numero(a, b, pode_negativo=False):
    return int((a + random() * (b - a)) * (1 if not pode_negativo else (1 if random() < 0.5 else -1)))


def gera_teste():
    n = int(random() * (2 ** 20)) + 3
    almejado = int(gera_numero(1, 2**20))
    inp = f'{n} {almejado}\n'
    for i in range(n):
        inp += f'{" " if i != 0 else ""}{gera_numero(1, 2 ** 20)} {gera_numero(0, (2 ** 20))}'
    return inp


def resolve(teste):
    linhas = teste.strip().split('\n')

    n, almejado = map(int, linhas[0].split())

    fornecedores = linhas[1].split()

    idas = 0
    maior = 0
    segundo_maior = 0
    terceiro_maior = 0
    for fornecedor in fornecedores:
        num = int(fornecedor)
        if num > maior:
            terceiro_maior = segundo_maior
            segundo_maior = maior
            maior = num
        elif num > segundo_maior:
            terceiro_maior = segundo_maior
            segundo_maior = num
        elif num > terceiro_maior:
            terceiro_maior = num

    cluster = maior + segundo_maior + terceiro_maior
    idas = almejado // cluster
    sobra = almejado % cluster
    idas *= 3

    if sobra > 0:
        idas += 1
        sobra -= maior

    if sobra > 0:
        idas += 1
        sobra -= segundo_maior

    if sobra > 0:
        idas += 1
        sobra -= terceiro_maior

    return f'{idas}\n'


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
