#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    string code;
    cin >> code;

    time_t start = time(nullptr);

    unordered_map<char, int> digit_counts;
    string decrypted_code = "";

    for (char digit : code) {
        digit_counts[digit]++;
        int decrypted_digit = (digit - '0' + digit_counts[digit] - 1) % primes[decrypted_code.size()];
        decrypted_code += to_string(decrypted_digit);
    }

    time_t end = time(nullptr);
    double response_time = difftime(end, start);

    if (response_time <= 1.0) {
        cout << decrypted_code << endl;
    } else {
        cout << "Response time exceeded!" << endl;
    }

    return 0;
}

