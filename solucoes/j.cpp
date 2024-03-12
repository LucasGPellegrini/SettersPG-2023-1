#include <iostream>

using namespace std;

int sumOfDigits(int N) {
    int sum = 0;
    while (N > 0) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    cout << sumOfDigits(N) << endl;
    return 0;
}

