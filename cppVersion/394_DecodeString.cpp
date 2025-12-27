#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
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
  struct node {
    string prestr;
    int cnt;
  };

  string decodeString(string s) {
    string alphaStr;
    string cntStr;
    vector<node> stk;
    int idx = 0;
    char ch;
    while (idx < s.size()) {
      while (isalpha(s[idx]))
        alphaStr.push_back(s[idx++]);
      while (isdigit(s[idx]))
        cntStr.push_back(s[idx++]);
      if (s[idx] == '[') {
      }
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
