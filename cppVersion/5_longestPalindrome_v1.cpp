// 211 ms 击败 44.65 %
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findPalindrome(string s, int leftPtr, int rightPtr) {
    while (leftPtr >= 0 && rightPtr < s.size() && s[rightPtr] == s[leftPtr]) {
      leftPtr--;
      rightPtr++;
    }

    leftPtr++;
    rightPtr--;

    return {leftPtr, rightPtr};
  }

  string longestPalindrome(string s) {
    int len = s.size();
    int center_right = len / 2;
    int center_left = center_right - 1;
    vector<int> r1, r2, r3, r4;
    vector<int> max_result = findPalindrome(s, center_left, center_right);

    while (center_right <= len - 1 || center_left >= 0) {
      r1 = findPalindrome(s, center_right, center_right);
      if (center_right + 1 >= len) {
        r2 = {0, 0};
      } else {
        r2 = findPalindrome(s, center_right, center_right + 1);
      }

      r3 = findPalindrome(s, center_left, center_left);
      if (center_left - 1 < 0) {
        r4 = {0, 0};
      } else {
        r4 = findPalindrome(s, center_left - 1, center_left);
      }

      vector<vector<int>> results = {r1, r2, r3, r4};
      auto maxIt = max_element(results.begin(), results.end(),
                               [](const vector<int> &a, const vector<int> &b) {
                                 return (a[1] - a[0]) < (b[1] - b[0]);
                               });
      vector<int> maxDiffResult = *maxIt;
      if (maxDiffResult[1] - maxDiffResult[0] > max_result[1] - max_result[0])
        max_result = maxDiffResult;

      center_right++;
      center_left--;
    }

    if (max_result[1] - max_result[0] <= 0)
      max_result = {0, 0};

    return s.substr(max_result[0], max_result[1] - max_result[0] + 1);
  }
};

int main() {
  Solution sol;
  string s = "ccc";
  cout << sol.longestPalindrome(s) << endl;
  return 0;
}
