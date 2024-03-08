#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


typedef std::pair<std::string, int> NomeNotaPair;


bool sortByNotaDecrescente(const NomeNotaPair& a, const NomeNotaPair& b) {
    return a.second > b.second;
}

int main() {
    int numNomes;
    std::cin >> numNomes;


    std::vector<NomeNotaPair> nomesNotas;


    for (int i = 0; i < numNomes; ++i) {
        std::string nome;
        int nota;
        std::cin >> nome >> nota;
        nomesNotas.push_back(std::make_pair(nome, nota));
    }

    std::sort(nomesNotas.begin(), nomesNotas.end(), sortByNotaDecrescente);


    for (std::vector<NomeNotaPair>::const_iterator it = nomesNotas.begin(); it != nomesNotas.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}
