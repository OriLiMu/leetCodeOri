#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <ios>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int leftEdgeSingle(int idx, string &s) {
    int left = idx, right = idx;
    while (right < s.size() && left >= 0 && s[left--] == s[right++]) {
    }

    return left + 1;
  }

  int leftEdgeDouble(int idx, string &s) {
    int left = idx, right = idx + 1;
    while (right < s.size() && left >= 0 && s[left--] == s[right++]) {
    }

    return left + 1;
  }

  void func(int rightIdx, string &s, vector<string> &cur, vector<int> &a1,
            vector<int> &a2, vector<vector<string>> &result) {
    if (rightIdx == s.size())
      return;
    for (int i = 0; i < a1.size(); ++i) {
      if (i >= rightIdx && a1[i] <= rightIdx) {
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<int> a1(s.size()); // get left edge list
    vector<int> a2(s.size() - 1);
    for (int i = 0; i < s.size(); ++i) {
      a1.push_back(leftEdgeSingle(i, s));
      a2.push_back(leftEdgeDouble(i, s));
    }

    vector<vector<string>> result;
    vector<string> cur;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
