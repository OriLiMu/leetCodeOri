#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    sort(p.begin(), p.end());
    unordered_set<char> us;
    for (auto c : p) {
      us.insert(c);
    }
    int curCnt = 0;
    int startIdx = 0;
    vector<int> r;
    for (int i = 0; i < s.size(); i++) {
      // cout << i << ": " << s[i] << ": curCnt: " << curCnt
      // << ", startIdx: " << startIdx
      // << ", tmpS: " << s.substr(startIdx, curCnt + 1) << endl;
      if (us.find(s[i]) != us.end()) {
        curCnt++;
      } else {
        // cout << "check" << endl;
        if (curCnt >= p.size()) {
          int tmpI = i;
          bool lastMatch = false;
          while (startIdx <= tmpI) {
            if (lastMatch) {
              if (s[startIdx - 1] == s[startIdx + p.size() - 1]) {
                r.push_back(startIdx);
              }
            } else {
              string tmpS = s.substr(startIdx, p.size());
              sort(tmpS.begin(), tmpS.end());
              if (tmpS == p) {
                r.push_back(startIdx);
              }
            }
            startIdx++;
          }
          curCnt = 0;
          tmpI = startIdx++;
        }
        curCnt = 0;
        startIdx = i + 1;
      }
      if (startIdx >= s.size())
        break;
    }

    while (startIdx < s.size()) {
      string tmpS = s.substr(startIdx, p.size());
      sort(tmpS.begin(), tmpS.end());
      if (tmpS == p) {
        r.push_back(startIdx);
      }
      startIdx++;
    }
    return r;
  }
};

int main() {
  Solution s;
  string ss = "acdcaeccde";
  string p = "c";
  vector<int> r = s.findAnagrams(ss, p);
  for (auto n : r) {
    cout << n << ", ";
  }
  cout << endl;
}
