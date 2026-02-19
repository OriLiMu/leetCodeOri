#include <climits>
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
    int r = INT_MIN;
    for (auto &n : nums) {
      // set the init value too small
      // 这个还是挺致命的一个问题
      int l = 1, insert_idx = 0;
      for (auto &st : vst) {
        if (st.v < n) {
          l = max(l, st.l + 1);
          insert_idx++;
        } else
          break;
      }

      // vst.insert(vst.begin() + insert_idx, {n, l});
      vst.emplace(vst.begin() + insert_idx, n, l);
      r = max(r, l);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 2, 1};
  v = {1, 2, 3};
  v = {10, 9, 2, 5, 3, 7, 101, 18};
  v = {0, 1, 0, 3, 2, 3};
  v = {7, 7, 7, 7, 7, 7, 7};
  cout << s.lengthOfLIS(v);
}
