#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ordena(const vector<string> &vetor) {
    vector<string> ordenado = {};
    vector<vector<string>> matriz_vogais = {{},{},{},{},{}};
    
    for (int i = 0; i < vetor.size(); i++) {
        string palavra = vetor[i];
        for (int j = 0; j < palavra.size(); j++) {
            if (tolower(palavra[j]) == 'a') {
                matriz_vogais[0].push_back(palavra);
                break;
            }
            else if (tolower(palavra[j]) == 'e') {
                matriz_vogais[1].push_back(palavra);
                break;
            }
            else if (tolower(palavra[j]) == 'i') {
                matriz_vogais[2].push_back(palavra);
                break;
            }
            else if (tolower(palavra[j]) == 'o') {
                matriz_vogais[3].push_back(palavra);
                break;
            }
            else if (tolower(palavra[j]) == 'u') {
                matriz_vogais[4].push_back(palavra);
                break;
            }
        }
    }
    
    for (int i = 0; i < matriz_vogais.size(); i++) {
        // ordena pelo tamanho
        sort(matriz_vogais[i].begin(), matriz_vogais[i].end(), []
            (const std::string& a, const std::string& b){
                return (a.size() < b.size()); 
            });
        for (int j = 0; j < matriz_vogais[i].size(); j++) {
            ordenado.push_back(matriz_vogais[i][j]);
        }
    }
    
    return ordenado;
}


int main() {
    vector<string> strings = {};
    string palavra;
    int qtd = 0;
    
    cin>>qtd;
    
    for (int i = 0; i < qtd; i++) {
        cin>>palavra;
        strings.push_back(palavra);
    }


    vector<string> res = ordena(strings);
    for (const string &s : res) {
        cout << s << endl;
    }

    return 0;
}
