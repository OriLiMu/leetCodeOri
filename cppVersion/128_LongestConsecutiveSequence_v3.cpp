#include <iostream>
#include <strings.h>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> u(nums.begin(), nums.end());
    int maxlen = 0;
    for (auto &n : nums) {
      int l = n, r = n;
      while (u.contains(l - 1)) {
        l--;
        u.erase(l);
      }
      while (u.contains(r + 1)) {
        r++;
        u.erase(r);
      }

      maxlen = max(maxlen, r - l + 1);
    }

    return maxlen;
  }
};

int main() {
  Solution s;
  vector<int> v = {100, 4, 200, 1, 2};
  v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  // 这个代码有个问题就是没考虑重复出现的点, 如果有重复出现的点可能删除之前的值
  v = {1, 0, 1, 2};
  // 差一个 u[n] = n, 那么这个意思是不是需要erase, 逻辑更干净
  v = {-6, 6, -9, -7, 0,  3, 4,  -2, 2,  -1, 9, -9, 5, -3,
       6,  1, 5,  -1, -2, 9, -9, -4, -6, -5, 6, -1, 3};
  cout << s.longestConsecutive(v) << endl;
}
