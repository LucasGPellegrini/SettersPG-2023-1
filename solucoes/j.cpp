#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "exprtk.hpp"

using namespace std;

typedef exprtk::expression<double> expression_t;
typedef exprtk::parser<double> parser_t;

bool evaluateExpression(const string& expression, double k) {
    parser_t parser;
    expression_t expr;
    expr.register_symbol_table("k", k);
    parser.compile(expression, expr);
    return expr.value();
}

bool checkExpressions(const vector<string>& expressions, double k) {
    for (const string& expr : expressions) {
        if (!evaluateExpression(expr, k)) {
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
