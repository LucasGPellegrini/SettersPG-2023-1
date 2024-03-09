#include <iostream>

long int factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return n * factorial(n - 1);
}

long int jogosComPlacar(int n, int m) {
  return (factorial(n + m) / factorial(n)) / factorial(m);
}

int main() {
  int N, M;
  std::cin >> N >> M;

  std::cout << jogosComPlacar(N, M) << std::endl;

  return 0;
}
