#include <iostream>

using namespace std;

long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  long long result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

int main(int argc, char *argv[]) {
  cout << factorial(3) << endl;
  cout << factorial(3) << endl;
  cout << factorial(1) << endl;
  return 0;
}
