#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Solution {
public:
  void Calc(vector<char> &remainCharVec, string &curResult,
            int unMatchedLeftCount, vector<string> &result) {
    if (remainCharVec.empty()) {
      result.push_back(curResult);
      return;
    }

    if (find(remainCharVec.begin(), remainCharVec.end(), '(') !=
        remainCharVec.end()) {
      curResult.push_back('(');
      auto it = std::find(remainCharVec.begin(), remainCharVec.end(), '(');
      if (it != remainCharVec.end()) {
        remainCharVec.erase(it);
      }
      unMatchedLeftCount++;
      Calc(remainCharVec, curResult, unMatchedLeftCount, result);
      remainCharVec.push_back('(');
      unMatchedLeftCount--;
      curResult.pop_back();
    }

    if (unMatchedLeftCount != 0) {
      curResult.push_back(')');
      auto it = std::find(remainCharVec.begin(), remainCharVec.end(), ')');
      if (it != remainCharVec.end()) {
        remainCharVec.erase(it);
      }
      unMatchedLeftCount--;
      Calc(remainCharVec, curResult, unMatchedLeftCount, result);
      remainCharVec.push_back(')');
      unMatchedLeftCount++;
      curResult.pop_back();
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    std::vector<char> remainCharVec(n * 2);
    std::fill(remainCharVec.begin(), remainCharVec.begin() + n, '(');
    std::fill(remainCharVec.begin() + n, remainCharVec.end(), ')');
    int unMatchedLeftCount = 0;
    string s = "";
    vector<string> result;
    Calc(remainCharVec, s, unMatchedLeftCount, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<string> r = s.generateParenthesis(3);
  for (auto s : r) {
    cout << s << endl;
  }
}
