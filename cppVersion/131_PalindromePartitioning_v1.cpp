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
    // 这一步是典型的代码错误
    // 这一步有问题, 如果s[left--] != s[right++] 那么实际上--和++已经发生了
    // while (right < s.size() && left >= 0 && s[left--] == s[right++]) {
    while (right < s.size() && left >= 0 && s[left] == s[right]) {
      left--;
      right++;
    }

    // 单中点至少有一个是对的
    return left + 1;
  }

  int leftEdgeDouble(int idx, string &s) {
    int left = idx, right = idx + 1;
    // 双中点可能一个都不对
    if (right >= s.size() || s[left] != s[right])
      return s.size(); // 这个是因为后面的使用, 所以这样设置
    while (right < s.size() && left >= 0 && s[left] == s[right]) {
      left--;
      right++;
    }

    return left + 1;
  }

  void func(int leftEdge, string &s, vector<vector<int>> &cur, vector<int> &a1,
            vector<int> &a2, vector<vector<vector<int>>> &result) {
    if (leftEdge == s.size()) {
      result.push_back(cur);
      return;
    }
    for (int i = leftEdge; i < a1.size(); ++i) {
      if (a1[i] <= leftEdge) {
        int rightEdge = i + i - leftEdge;
        cur.push_back({leftEdge, rightEdge});
        func(rightEdge + 1, s, cur, a1, a2, result);
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
        cur.push_back({leftEdge, rightEdge});
        func(rightEdge + 1, s, cur, a1, a2, result);
        cur.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<int> a1, a2; // get left edge list
    for (int i = 0; i < s.size(); ++i) {
      // 很有意思, 这个a1, a2实际上你之前已经设置了大小,
      // 所以这个时候再用push_back就会放到更后面
      a1.push_back(leftEdgeSingle(i, s));
      a2.push_back(leftEdgeDouble(i, s));
      // a1[i] = leftEdgeSingle(i, s);
      // // a2 初始的大小是 size - 1, 但是你的循环的次数是 size,
      // 很容易忽略的问题 a2[i] = leftEdgeDouble(i, s);
    }
    a2.pop_back(); // 最后一个值无效, 因为没有右中点

    vector<vector<vector<int>>> result;
    vector<vector<int>> cur;
    func(0, s, cur, a1, a2, result);
    vector<vector<string>> r;
    vector<string> cur_r;
    for (auto &vvi : result) {
      for (auto &vi : vvi) {
        cur_r.push_back(s.substr(vi[0], vi[1] - vi[0] + 1));
      }
      r.push_back(cur_r);
      cur_r.clear();
    }

    return r;
  }
};

int main() {
  Solution s;
  string ts = "abcc";
  s.partition(ts);
}
