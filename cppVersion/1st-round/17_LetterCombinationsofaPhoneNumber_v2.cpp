#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
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
  void func(string &digits, int startIdx, string &cur, vector<string> &result,
            vector<vector<char>> &phoneMap) {
    if (startIdx >= digits.size()) {
      result.push_back(cur);
      return;
    }

    int charIdx = digits[startIdx] - '2';
    for (auto &c : phoneMap[charIdx]) {
      cur.push_back(c);
      func(digits, startIdx + 1, cur, result, phoneMap);
      cur.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    vector<vector<char>> phoneMap = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                     {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                     {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                     {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    int startIdx = 0;
    string cur;
    vector<string> result;
    func(digits, startIdx, cur, result, phoneMap);
    return result;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
