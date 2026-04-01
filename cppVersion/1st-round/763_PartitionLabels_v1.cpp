#include <iostream>
#include <strings.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> partitionLabels(string s) {
    unordered_map<char, vector<int>> d;
    for (int i = 0; i < s.size(); ++i) {
      if (!d.contains(s[i]) || d[s[i]].size() == 1)
        d[s[i]].push_back(i);
      else
        d[s[i]][1] = i;
    }
    int l = 0, r;
    vector<int> result;
    while (l < s.size()) {
      r = d[s[l]].back();
      for (int i = l; i <= r; i++)
        r = max(r, d[s[i]].back());
      result.push_back(r - l + 1);
      l = r + 1;
    }

    return result;
  }
};

int main() {
  Solution s;
  string str = "ababcbacadefegdehijhklij";
  // str = "abc";
  for (const auto &elem : s.partitionLabels(str)) {
    cout << elem << " ";
  }
  cout << endl;
}
