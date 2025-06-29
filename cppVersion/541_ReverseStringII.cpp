#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseStringPiece(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
      char c = s[i];
      s[i] = s[s.size() - 1 - i];
      s[s.size() - i - 1] = c;
    }
    return s;
  }
  string reverseStr(string s, int k) {
    int currentIndex = 0;
    while (true) {
      if (currentIndex + k < s.size()) {
        reverse(s.begin() + currentIndex, s.begin() + currentIndex + k);
      } else {
        reverse(s.begin() + currentIndex, s.begin() + s.size());
      }
      currentIndex += 2 * k;
      if (currentIndex >= s.size())
        break;
    }

    return s;
  }
};

int main() {
  Solution s;
  string str = "abcd";
  int k = 4;
  cout << s.reverseStr(str, k) << endl;
}
