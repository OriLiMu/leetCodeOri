// 18ms beat 70%
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
  void getLargerEdgeGroup(vector<int> &result, vector<int> tmp) {
    if (tmp[1] - tmp[0] > result[1] - result[0]) {
      result[0] = tmp[0];
      result[1] = tmp[1];
    }
  }
  string longestPalindrome(string s) {
    m_s = s;
    int leftPtr = s.size() / 2 - 1;
    int rightPtr = leftPtr + 1;
    int len = s.size();
    vector<int> result = findPalindrome(leftPtr, rightPtr);
    vector<vector<int>> tmp_results;
    while (leftPtr >= 1 || rightPtr <= len - 2) {
      tmp_results.clear();
      int half_max_len = 0;
      if (result[1] != result[0]) {
        half_max_len = (result[1] - result[0]) % 2
                           ? (result[1] - result[0]) / 2
                           : (result[1] - result[0]) / 2 + 1;
      }
      if (leftPtr > half_max_len) {
        tmp_results.push_back(findPalindrome(leftPtr - 1, leftPtr));
        tmp_results.push_back(findPalindrome(leftPtr, leftPtr));
      }
      if ((len - rightPtr - 1) >=
          half_max_len) { // 这里应该是 >= 因为你偏大的条件是奇数字符串.
                          // 如果substring也是奇数的这个就没有意义了
        tmp_results.push_back(findPalindrome(rightPtr, rightPtr + 1));
        tmp_results.push_back(findPalindrome(rightPtr, rightPtr));
      }

      // 如果这里不去check tmp_results.empty()，会报错 LeetCode报错,
      // 但是我这边IDE ok
      if (!tmp_results.empty()) {
        auto tmp_max = max_element(tmp_results.begin(), tmp_results.end(),
                                   [](vector<int> &a, vector<int> &b) {
                                     return a[1] - a[0] < b[1] - b[0];
                                   });
        getLargerEdgeGroup(result, *tmp_max);
      }
      leftPtr--;
      rightPtr++;
    }

    if (result[0] > result[1]) {
      result = {0, 0};
    }

    return m_s.substr(result[0], result[1] - result[0] + 1);
  }
};

int main() {
  Solution sol;
  string s = "babadada";
  cout << sol.longestPalindrome(s) << endl;
  return 0;
}
