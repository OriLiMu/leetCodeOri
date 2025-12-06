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
  vector<int> a1, a2; // get left edge list
  vector<vector<string>> result;

  int leftEdge(int idx, string &s, bool isDouble) {
    int left = idx, right = idx;
    if (isDouble) {
      right++;
      if (right < s.size() && s[left] != s[right]) {
        return s.size();
      }
    }
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }

    return left + 1;
  }

  void func(int leftEdge, string &s, vector<string> &cur) {
    if (leftEdge == -1)
      return;
    if (leftEdge == s.size()) {
      result.push_back(cur);
      return;
    }
    for (int i = leftEdge; i < a1.size(); ++i) {
      if (a1[i] <= leftEdge) {
        int rightEdge = i + i - leftEdge;
        cur.push_back(s.substr(leftEdge, rightEdge - leftEdge + 1));
        func(rightEdge + 1, s, cur);
        cur.pop_back();
      }
    }

    // 最后一个, 不能凑成双中点
    if (leftEdge == s.size() - 1)
      return;

    for (int leftCt = leftEdge; leftCt < a2.size(); ++leftCt) {
      if (a2[leftCt] <=
          leftEdge) { // 你另一个地方用了这个逻辑把值设置成size, 这个就不通过,
                      // 达到效果, 但是有点"非意义定义", 有点卡数字的嫌疑
        // 看似精巧但是实际上还是把逻辑复杂化了
        int rightEdge = leftCt + 1 + leftCt - leftEdge;
        cur.push_back(s.substr(leftEdge, rightEdge - leftEdge + 1));
        func(rightEdge + 1, s, cur);
        cur.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    for (int i = 0; i < s.size(); ++i) {
      // 很有意思, 这个a1, a2实际上你之前已经设置了大小,
      // 所以这个时候再用push_back就会放到更后面
      a1.push_back(leftEdge(i, s, false));
      a2.push_back(leftEdge(i, s, true));
      // a1[i] = leftEdgeSingle(i, s);
      // // a2 初始的大小是 size - 1, 但是你的循环的次数是 size,
      // 很容易忽略的问题 a2[i] = leftEdgeDouble(i, s);
    }
    a2.pop_back(); // 最后一个值无效, 因为没有右中点

    vector<string> cur;
    func(0, s, cur);
    // vector<vector<string>> r;
    // vector<string> cur_r;
    // for (auto &vvi : result) {
    //   for (auto &vi : vvi) {
    //     cur_r.push_back(s.substr(vi[0], vi[1] - vi[0] + 1));
    //   }
    //   r.push_back(cur_r);
    //   cur_r.clear();
    // }

    return result;
  }
};

int main() {
  // Solution s;
  // string ts = "abcc";
  // s.partition(ts);
  //  int n = s.size();
  // 预处理所有回文子串
  int n = 10;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      cout << "m: " << i << ", n: " << j << endl;
    }
  }
}
