#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    sort(p.begin(), p.end());
    // const auto charCountBaseline = buildCharMap(text);
    // auto charCountRuntime = charCountBaseline;
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
