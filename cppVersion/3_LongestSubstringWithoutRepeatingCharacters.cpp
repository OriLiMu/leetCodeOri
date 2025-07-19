#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> unqChars;
    int result = 0;
    int left = 0, right = 0;
    while (right < s.size()) {
      if (!unqChars.count(s[right])) {
        unqChars.insert(s[right++]);
        result = max(static_cast<int>(unqChars.size()), result);
      } else {
        size_t pos = s.find(s[right], left) + 1;
        for (int i = left; i < pos; i++) {
          unqChars.erase(s[i]);
        }
        left = pos;
        if (right < left) {
          right = left;
        }
      }
    }

    return result;
  }
};
int main() {
  Solution s;
  // string a = "pwwkew";
  // string a = "cccc";
  string a = "aabaab!bb";
  cout << s.lengthOfLongestSubstring(a) << endl;
}
