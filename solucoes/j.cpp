#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono> // For time measurement
using namespace std;
using namespace std::chrono; // For time measurement

bool evaluateExpression(const string& expr, int k) {
    // Basic implementation to evaluate a mathematical expression
    // Here, you may use a more robust mathematical expression evaluation library
    // This implementation is for demonstration purposes only
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

    // Evaluate the last number in the expression
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

    // Check if the expression is true for the value of k
    return result == k;
}

bool solve(const vector<string>& expressions, int k, int currentIndex) {
    if (currentIndex == expressions.size()) {
        // All expressions have been satisfied
        return true;
    }

    // Try different values for k recursively
    for (int i = 0; i <= k; ++i) {
        if (evaluateExpression(expressions[currentIndex], i)) {
            // If the current expression is true, move to the next expression
            if (solve(expressions, k, currentIndex + 1)) {
                return true;
            }
        }
    }

    // No combination found for the current expression
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

    // Start time measurement
    auto start = high_resolution_clock::now();

    while (true) {
        if (solve(expressions, k, 0)) {
            cout << k << endl;
            break;
        }
        ++k;

        // Check elapsed time
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(end - start).count();
        if (duration > 1) {
            cout << "Time limit exceeded!" << endl;
            break;
        }
    }

    return 0;
}
