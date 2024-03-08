#include <iostream>

unsigned long long calcularFatorial(int n) {
    unsigned long long fatorial = 1;

    for (int i = 1; i <= n; ++i) {
        fatorial *= i;
    }

    return fatorial;
}

int main() {
    int numero;

    std::cin >> numero;

    if (numero < 0) {

    } else {
        unsigned long long resultado = calcularFatorial(numero);
        std::cout << resultado << std::endl;
    }

    return 0;
}
