#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (isPrime(i))
            count++;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countPrimes(N) << endl;
    return 0;
}
