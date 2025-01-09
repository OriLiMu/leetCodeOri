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
  string longestPalindrome(string s) {
    m_s = s;
    int leftPtr = s.size() / 2 - 1;
    int rightPtr = leftPtr + 1;
    int len = s.size();
    vector<int> result = findPalindrome(leftPtr, rightPtr);
    vector<vector<int>> tmp_results;
    while (leftPtr >= 1 || rightPtr <= len - 2) {
      tmp_results.clear();
      // 偶数回文
      if (leftPtr - 1 >= 0) {
        tmp_results.push_back(findPalindrome(leftPtr - 1, leftPtr));
      }
      if (rightPtr + 1 <= len - 1) {
        tmp_results.push_back(findPalindrome(rightPtr, rightPtr + 1));
      }

      // 奇数回文
      tmp_results.push_back(findPalindrome(leftPtr, leftPtr));
      tmp_results.push_back(findPalindrome(rightPtr, rightPtr));

      // 获取本轮最大值
      auto tmp_max = max_element(tmp_results.begin(), tmp_results.end(),
                                 [](vector<int> &a, vector<int> &b) {
                                   return a[1] - a[0] < b[1] - b[0];
                                 });
      // 和历史最大值比较
      getLargerEdgeGroup(result, *tmp_max);
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
  string s = "ccc";
  cout << sol.longestPalindrome(s) << endl;
  return 0;
}
