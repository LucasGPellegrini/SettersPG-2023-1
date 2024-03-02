#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool anagrama(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, int> ocorrencias;

    for (char c : s1) {
        ocorrencias[c]++;
    }

    for (char c : s2) {
        if (ocorrencias.find(c) == ocorrencias.end() 
            || ocorrencias[c] == 0) {
            return false;
        }
        ocorrencias[c]--;
    }

    return true;
}

int main() {
    string s1, s2;
    
    cin >> s1;
    cin >> s2;
    
    int quantidade = 0;
    
    for (int i = 0; i <= s1.length() - s2.length(); i++) {
        if (anagrama(s1.substr(i, s2.length()), s2)) {quantidade ++;}
    }

    cout << quantidade;

    return 0;
}
