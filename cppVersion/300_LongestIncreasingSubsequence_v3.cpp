#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> v;
    for (auto &n : nums) {
      auto it = lower_bound(v.begin(), v.end(), n);
      if (it == v.end())
        v.push_back(n);
      else
        *it = n;
    }
    return v.size();
  }
};

int main() {
  Solution s;
  vector<int> v = {
      1,
      2,
      3,
  };
  v = {3, 2, 1};
  v = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << s.lengthOfLIS(v) << endl;
}
