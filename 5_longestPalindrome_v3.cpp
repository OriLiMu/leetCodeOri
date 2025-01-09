// 39ms 68.74%
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  string m_s;

public:
  vector<int> findPalindrome(int leftPtr, int rightPtr) {
    int len = m_s.size();
    if (leftPtr < 0 || leftPtr >= len || rightPtr < 0 || rightPtr >= len) {
      return {0, 0};
    }

    while (leftPtr <= rightPtr && leftPtr >= 0 && rightPtr < len &&
           m_s[leftPtr] == m_s[rightPtr]) {
      leftPtr--;
      rightPtr++;
    }
    return {++leftPtr, --rightPtr};
  }
  void getLargerEdgeGroup(vector<int> &result, vector<int> &tmp) {
    if (tmp[1] - tmp[0] > result[1] - result[0]) {
      result[0] = tmp[0];
      result[1] = tmp[1];
    }
  }

  string longestPalindrome(string s) {}
};

int main() {
  Solution sol;
  string s = "ccc";
  cout << sol.longestPalindrome(s) << endl;
  return 0;
}
