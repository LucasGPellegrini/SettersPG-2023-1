
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

typedef std::pair<std::string, int> NomeNotaPair;
typedef std::pair<int, NomeNotaPair> IndiceNomeNotaPairPair;

bool sortByNotaDecrescente(const IndiceNomeNotaPairPair& a,
                           const IndiceNomeNotaPairPair& b) {
  if (a.second.second == b.second.second) {
    return a.first < b.first;
  }
  return a.second.second > b.second.second;
}

int main() {
  int numNomes;
  std::cin >> numNomes;

  std::vector<IndiceNomeNotaPairPair> nomesNotas;

  for (int i = 0; i < numNomes; ++i) {
    std::string nome;
    int nota;
    std::cin >> nome >> nota;
    nomesNotas.push_back(std::make_pair(i, std::make_pair(nome, nota)));
  }

  std::sort(nomesNotas.begin(), nomesNotas.end(), sortByNotaDecrescente);

  for (std::vector<IndiceNomeNotaPairPair>::const_iterator it =
           nomesNotas.begin();
       it != nomesNotas.end(); ++it) {
    std::cout << it->second.first << " " << it->second.second << std::endl;
  }

  return 0;
}
