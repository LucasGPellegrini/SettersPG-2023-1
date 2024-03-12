#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

double evaluateExpression(const string& expression, double k) {
    string modifiedExpression = expression;
    size_t pos = modifiedExpression.find("k");
    while (pos != string::npos) {
        modifiedExpression.replace(pos, 1, to_string(k));
        pos = modifiedExpression.find("k", pos + 1);
    }

    stringstream ss(modifiedExpression);
    double result;
    ss >> result;
    return result;
}

bool checkExpressions(const vector<string>& expressions, double k) {
    for (const string& expr : expressions) {
        if (evaluateExpression(expr, k) != 0) {
            return false;
        }
    }
    return true; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> expressions(n);

    for (int i = 0; i < n; ++i) {
        cin.ignore();
        getline(cin, expressions[i]);
    }

    for (int k = 0; k <= 100; ++k) {
        if (checkExpressions(expressions, k)) {
            cout << k << "\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}
