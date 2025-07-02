#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<char>> phoneMap = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                   {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                   {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                   {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

  void getString(string remainDigit, vector<string> &result, string curStr) {
    if (remainDigit.size() == 0) {
      result.push_back(curStr);
      return;
    } else {
      int c = remainDigit[0] - '2';
      remainDigit = remainDigit.substr(1);
      for (int i = 0; i < phoneMap[c].size(); i++) {
        string tmp(curStr);
        tmp.push_back(phoneMap[c][i]);
        getString(remainDigit, result, tmp);
      }
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};
    vector<string> res;
    getString(digits, res, "");
    return res;
  }
};

int main() {
  Solution s;
  vector<string> res = s.letterCombinations("23");
  for (auto &str : res) {
    cout << str << endl;
  }
  return 0;
}
