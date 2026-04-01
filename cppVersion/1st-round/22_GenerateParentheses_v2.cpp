#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> status;
    vector<string> result;
    status.push_back({""});
    status.push_back({"()"});
    // n 项逐个计算
    for (int i = 2; i <= n; i++) {
      vector<string> curResult;
      // 设置内项参数, 计算括号外项
      for (int j = 0; j < i; j++) {
        vector<string> inParethesis = status[j];
        vector<string> outParethesis = status[i - 1 - j];
        for (const auto &inParethesis : inParethesis) {
          for (const auto &outParethesis : outParethesis) {
            string tmp = "(" + inParethesis + ")" + outParethesis;
            curResult.push_back(tmp);
          }
        }
      }
      status.push_back(curResult);
    }
    return status[n];
  }
};

int main() {
  Solution s;
  vector<string> result = s.generateParenthesis(4);
  for (const auto &i : result) {
    cout << i << endl;
  }
  return 0;
}

