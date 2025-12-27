#include <cctype>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  struct node {
    string prestr;
    int cnt;
    node(string s, int n) : prestr(s), cnt(n) {};
  };

  string decodeString(string s) {
    // 这个r的概念也有点乱
    string alphaStr, cntStr, r;
    vector<node> stk;
    int idx = 0;
    char ch;
    bool isLBOn = false;
    while (idx < s.size()) {
      while (isalpha(s[idx]))
        if (isLBOn)
          alphaStr.push_back(s[idx++]);
        else
          r += s[idx++];

      while (isdigit(s[idx]))
        cntStr.push_back(s[idx++]);
      if (s[idx] == '[') {
        isLBOn = true;
        int cnt = stoi(cntStr);
        stk.push_back(node(alphaStr, cnt));
        cntStr.clear();
        alphaStr.clear();
        idx++;
      }

      if (s[idx] == ']') {
        node tn = stk.back();
        string st = tn.prestr;
        if (alphaStr.empty()) {
          st = "";
          alphaStr = tn.prestr;
        }
        // 你这里有一个预设的前提, 就是alphaStr一定走过了一些字母,
        // 然而可能出现两个]]紧挨着的情况
        for (int i = 0; i < tn.cnt; ++i)
          st += alphaStr;
        stk.pop_back();
        if (stk.empty()) {
          r += st;
          isLBOn = false;
        } else
          stk.back().prestr += st;
        alphaStr.clear();
        cntStr.clear();
        idx++;
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  string sv = "3[a]2[bc]";
  sv = "3[a]";
  sv = "3[a2[c]]";
  sv = "4[e1[f]]";
  sv = "2[2[ye1[f]]]";
  // 两数字相连的时候出现问题
  // 问题在于你下面的1f算完之后直接贴给了ye, 中间没有X2
  sv = "2[ye2[1[f]]]";
  // 这个就暴露出来你代码的问题, 你把上级和下级的字符串放一起了
  // 逻辑理解顺序上有问题的代码是不能接受的
  // 写一个代码之前先用语言描述出来你的做题的逻辑过程
  // sv = "2[pq4[2[j]]]";
  cout << s.decodeString(sv);
}
