#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> evenOddBit(int n) {
    int oddCount = 0;
    int evenCount = 0;
    int bitCount = 0;
    while (true) {
      if (n == 0) {
        return {evenCount, oddCount};
      }

      if (n & 1) {
        evenCount++;
      }
      n >>= 1;
      if (n & 1) {
        oddCount++;
      }
      n >>= 1;
    }
  }
};
int main() {
  Solution s;
  vector<int> v = s.evenOddBit(17);
  cout << v[0] << ":" << v[1] << endl;
}
