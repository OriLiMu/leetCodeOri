#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> v(26);
    vector<int> rst;
    for (auto &c : p)
      v[c - 'a']++;
    vector<int> tmp = v;
    int head = 0;
    for (int i = 0; i < s.size(); i++) {
      int char_idx = s[i] - 'a';
      if (!v[char_idx]) {
        tmp = v;
        head = i + 1;
      } else {
        tmp[char_idx]--;
        while (tmp[char_idx] < 0)
          tmp[s[head++] - 'a']++;
        if (i - head + 1 == p.size()) {
          rst.push_back(head);
          tmp[s[head] - 'a']++;
          head++;
        }
      }
    }

    return rst;
  }
};

int main() {
  // 1. 输入: s = "cbaebabacd", p = "abc"
  // 输出: {0,6}
  // 2. 输入: s = "abab", p = "ab"
  // 输出: {0,1,2}
  Solution s;
  string str = "cbaebabacd";
  string p = "abc";
  str = "ababcaa";
  p = "abac";
  str = "a";
  p = "b";
  vector<int> r = s.findAnagrams(str, p);
  for (const auto &elem : r) {
    cout << elem << " ";
  }
  cout << endl;
}
