#include <iostream>
#include <stdlib.h>

int main(void) {
  int N;
  std::cin >> N;

  int distancia_total = 0;
  int last_x = 0, last_y = 0;
  int atual_x, atual_y; 

  for (int i = 0; i < N; i++) {
    std::cin >> atual_x;
    std::cin >> atual_y;

    distancia_total += abs(atual_x - last_x) + abs(atual_y - last_y);
    last_x = atual_x;
    last_y = atual_y;
  }

  std::cout << distancia_total << std::endl;

  return 0;
}
