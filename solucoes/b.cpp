#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

std::string obterIniciais(const std::string& nome) {
    std::string iniciais = "";


    iniciais += toupper(nome[0]);


    for (size_t i = 1; i < nome.length(); ++i) {
        if (isspace(nome[i])) {

            iniciais += toupper(nome[i + 1]);
        }
    }

    return iniciais;
}

int main() {
    std::string nome;
    std::cout << "Digite o nome: ";
    std::getline(std::cin, nome);

    std::string iniciais = obterIniciais(nome);
    std::cout  << iniciais << std::endl;

    return 0;
}
