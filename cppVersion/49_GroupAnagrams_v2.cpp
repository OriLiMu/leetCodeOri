#include <algorithm>
#include <iostream>
#include <strings.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> u;
    vector<vector<string>> r;
    for (auto &str : strs) {
      string sorted = str;
      sort(sorted.begin(), sorted.end());
      u[sorted].emplace_back(str);
    }

    for (auto &it : u) {
      r.emplace_back(it.second);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> r = s.groupAnagrams(v);
  for (const auto &row : r) {
    for (const auto &elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
}
