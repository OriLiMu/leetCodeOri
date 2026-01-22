#include <iostream>
#include <strings.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> partitionLabels(string s) {
    // unordered_map<char, int> d;
    vector<int> d(26);
    for (int i = 0; i < s.size(); ++i)
      d[s[i] - 'a'] = i;
    int l = 0, r = 0;
    vector<int> result;
    for (int i = 0; i < s.size(); ++i) {
      r = max(r, d[s[i] - 'a']);
      if (i == r) {
        result.push_back(r - l + 1);
        l = r + 1;
      }
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
