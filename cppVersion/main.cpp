#include <chrono>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> us;
    int last_left = 0;
    int rst = 0;
    for (int i = 0; i < s.size() && last_left < s.size(); i++) {
      if (us.contains(s[i])) {
        while (s[last_left] != s[i])
          us.erase(s[last_left++]);
        last_left++;
      } else {
        rst = max(rst, i - last_left + 1);
        us.insert(s[i]);
      }
    }

    return rst;
  }
};

int main() {
  Solution s;
  string str = "abcabcbb";
  str = "bbbbb";
  str = "a";
  str = "abccbaacabdcea bdea ";
  cout << s.lengthOfLongestSubstring(str) << endl;
}
