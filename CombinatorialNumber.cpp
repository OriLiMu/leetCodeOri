#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
  int factorial(int n) {
    if (n == 0 || n == 1)
      return 1;
    int result = 1;
    while (n > 0) {
      result *= n--;
    }

    return result;
  }

  int combinatorial(int k, int n) {
    return factorial(n) / (factorial(k) * factorial(n - k));
  }

  vector<int> getRow(int rowIndex) {
    vector<int> result;
    if (rowIndex == 0) {
      return {1};
    }
    for (int i = 0; i < rowIndex + 1; i++) {
      result.push_back(combinatorial(i, rowIndex));
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> result = s.getRow(3);
  cout << "this is the test" << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
