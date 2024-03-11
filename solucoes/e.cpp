#include <iostream>

int main() {
  int fornecedores, volume_almejado;
  std::cin >> fornecedores;
  std::cin >> volume_almejado;

  int maior = -1, segundo_maior = -1, terceiro_maior = -1;

  int fornecedor;
  for (int i = 0; i < fornecedores; i++) {
    std::cin >> fornecedor;

    if (fornecedor > terceiro_maior) {
      terceiro_maior = fornecedor;

      if (terceiro_maior > segundo_maior) {
        terceiro_maior = segundo_maior;
        segundo_maior = fornecedor;

        if (segundo_maior > maior) {
          segundo_maior = maior;
          maior = fornecedor;
        }
      }
    }
  }

  int cluster = maior + segundo_maior + terceiro_maior;

  int idas = volume_almejado / cluster;
  int sobrou = volume_almejado - idas * cluster;
  idas *= 3;

  if (sobrou > 0) {
    idas++;
    sobrou -= maior;
  }

  if (sobrou > 0) {
    idas++;
    sobrou -= segundo_maior;
  }

  std::cout << idas << std::endl;

  return 0;
}
