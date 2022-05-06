#include <iostream>

using namespace std;

int main() {
  for (int i = 0; i < 100; i++) {
    string result = "";
    if (i % 3 == 0) result += "Fizz";
    if (i % 5 == 0) result += "Buzz";
    if (result == "") result = to_string(i);
    cout << result << std::endl;
  }
  return 0;
}