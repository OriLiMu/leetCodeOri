#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  struct st {
    int v;
    int l;
  };

  int lengthOfLIS(vector<int> &nums) {
    vector<st> vst;
    int max_l = 1, idx = 0, r = 1;
    for (auto &n : nums) {
      for (auto &st : vst) {
        if (st.v < n) {
          max_l = max(max_l, st.l + 1);
          idx++;
        } else
          break;
      }

      r = max(max_l, r);
      vst.emplace(vst.begin() + idx, n, max_l);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 2, 1};
  v = {1, 2, 3};
  cout << s.lengthOfLIS(v);
}
