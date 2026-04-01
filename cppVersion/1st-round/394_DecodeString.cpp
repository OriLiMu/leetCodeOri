#include <algorithm>
#include <cctype>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  struct node {
    int n;
    string s;
    node(int n) : n(n) {};
  };

  string decodeString(string s) {
    string r;
    int idx = 0;
    vector<node> stk;
    stk.push_back(node(1));
    while (idx < s.size()) {
      while (isalpha(s[idx])) {
        stk.back().s.push_back(s[idx]);
        idx++;
      }

      // start meet []
      string cnt_str;
      while (isdigit(s[idx]))
        cnt_str.push_back(s[idx++]);

      if (s[idx] == '[')
        stk.push_back(node(stoi(cnt_str)));
      if (s[idx] == ']') {
        string ts = "";
        for (int i = 0; i < stk.back().n; ++i)
          ts += stk.back().s;
        stk.pop_back();
        stk.back().s += ts;
      }
      idx++;
    }

    return stk.back().s;
  }
};

int main() {
  Solution s;
  string sv = "3[a]2[bc]";
  sv = "3[a]";
  sv = "3[a2[c]]";
  sv = "4[e1[f]]";
  // 两数字相连的时候出现问题
  // 问题在于你下面的1f算完之后直接贴给了ye, 中间没有X2
  // 我的代码在连续的两个数字之后崩溃
  // 根本原因还是核心的逻辑的理解不够
  //
  // --------------------------------------------------
  // 这个是错误的例子我们跟一下
  // sv = "2[ye2[1[f]]]" , 给出的答案 yefyefyefyef
  // sv = "ye2[1[f]]"; // 这个是对的
  // 找到问题了
  // stk.back().prestr += st; 这个st 不能直接加给上一级的prestr,
  // 因为st还应该有一个乘数的过程, st 应该是上一级的 alphaStr
  // 先考虑为什么其他的测试例是对的
  // sv = "2[ye2[1[f]]]";
  // --------------------------------------------------
  // 这个是对的
  sv = "2[2[ye1[f]]]";
  // 这个是错的
  sv = "2[k2[ye1[f]]]";

  // 这个就暴露出来你代码的问题, 你把上级和下级的字符串放一起了
  // 逻辑理解顺序上有问题的代码是不能接受的
  // 写一个代码之前先用语言描述出来你的做题的逻辑过程
  // sv = "2[pq4[2[j]]]";
  cout << s.decodeString(sv);
}
