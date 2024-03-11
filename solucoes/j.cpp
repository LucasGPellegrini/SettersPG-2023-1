#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool evaluateExpression(const string& expr, int k) {
    int result = 0;
    string currentNum = "";
    char lastOperator = '+';

    for (char c : expr) {
        if (isdigit(c)) {
            currentNum += c;
        } else {
            int num = stoi(currentNum);
            switch (lastOperator) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    result /= num;
                    break;
                case '^':
                    result = pow(result, num);
                    break;
                default:
                    break;
            }
            currentNum = "";
            lastOperator = c;
        }
    }

    int num = stoi(currentNum);
    switch (lastOperator) {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            result /= num;
            break;
        case '^':
            result = pow(result, num);
            break;
        default:
            break;
    }

    return result == k;
}

bool solve(const vector<string>& expressions, int k, int currentIndex) {
    if (currentIndex == expressions.size()) {
        return true;
    }

    for (int i = 0; i <= k; ++i) {
        if (evaluateExpression(expressions[currentIndex], i)) {
            if (solve(expressions, k, currentIndex + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> expressions(n);
    for (int i = 0; i < n; ++i) {
        cin >> expressions[i];
    }

    int k = 0;

    auto start = high_resolution_clock::now();

    while (true) {
        if (solve(expressions, k, 0)) {
            cout << k << endl;
            break;
        }
        ++k;

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(end - start).count();
        if (duration > 1) {
            cout << "Time limit exceeded!" << endl;
            break;
        }
    }

    return 0;
}
