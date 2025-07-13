#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, int> m;
    vector<vector<string>> result;
    int maxIdx = 0;
    for (int i = 0; i < strs.size(); i++) {
      string tmp = strs[i];
      sort(tmp.begin(), tmp.end());
      if (m.find(tmp) != m.end()) {
        result[m[tmp]].push_back(std::move(strs[i]));
      } else {
        m[tmp] = maxIdx++;
        result.push_back({strs[i]});
      }
    }

    return result;
  }
};
int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // vector<string> strs = {"a"};
  Solution s;
  vector<vector<string>> r = s.groupAnagrams(strs);
  for (auto v : r) {
    for (auto str : v) {
      cout << str << ", ";
    }
    cout << endl;
  }
}
