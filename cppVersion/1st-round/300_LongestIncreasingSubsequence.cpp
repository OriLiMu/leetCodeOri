#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
  struct myst {
    int v;
    int l;
  };

public:
  int lengthOfLIS(vector<int> &nums) {
    int r = 0;
    vector<myst> v(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      myst st;
      st.v = nums[i];
      st.l = 1;
      for (int k = 0; k < i; ++k)
        if (v[k].v < st.v && v[k].l >= st.l)
          st.l = v[k].l + 1;
      v[i] = st;
      r = max(r, st.l);
    }

    return r;
  }
};
int main() {
  Solution s;
  vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
  v = {0, 1, 0, 3, 2, 3};
  v = {7, 7, 7, 7, 7, 7, 7};
  cout << s.lengthOfLIS(v) << endl;
}
