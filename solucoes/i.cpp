#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int main() {
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  string code;
  cin >> code;

  clock_t start = clock();

  string decrypted_code = "";
  for (int i = 0; i < code.length(); i++) {
    int original_digit = code[i] - '0';
    int cycle_position = 0;
    for (int j = 0; j < i; j++) {
      if (code[j] == code[i]) {
        cycle_position++;
      }
    }
    int decrypted_digit = (original_digit + cycle_position) % primes[i];
    decrypted_code += to_string(decrypted_digit);
  }

  clock_t end = clock();
  double response_time = (double)(end - start) / CLOCKS_PER_SEC;

  if (response_time <= 1.0) {
    cout << decrypted_code << endl;
  } else {
    cout << "Response time exceeded!" << endl;
  }

  return 0;
}
