#include <algorithm>
#include <iostream>
#include <strings.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> u;
    for (auto &n : nums) {
      if (u.contains(n))
        continue;
      bool le = u.contains(n + 1);
      bool re = u.contains(n - 1);
      if (le && re) {
        int rre = u[n + 1];
        int rle = u[n - 1];
        u[rre] = rle;
        u[rle] = rre;
        // 注意这个步骤没有添加 n, 所以后面, 如果有重复的n进来还会有问题
        // 总体还是逻辑的混乱
        u[n] = n;

        // cout << "k:" << rre << ", v:" << u[n + 1] << endl;
        // cout << "k:" << rle << ", v:" << u[n - 1] << endl;
      } else if (le) {
        u[n] = u[n + 1];
        u[u[n + 1]] = n;
        // cout << "k1:" << n << ", v:" << u[n + 1] << endl;
        // cout << "k1:" << u[n + 1] << ", v:" << n << endl;
      } else if (re) {
        u[n] = u[n - 1];
        u[u[n - 1]] = n; // 这步已经把对应的值clear
        // cout << "k2:" << n << ", v:" << u[n - 1] << endl;
        // cout << "k2:" << u[n - 1] << ", v:" << n << endl;
      } else
        u[n] = n;
    }

    int maxlen = 0;
    for (auto &kv : u) {
      // 这里少了一个绝对值的问题, 但是这里又需要考虑如果有负数的情况.
      maxlen = max(kv.second - kv.first + 1, maxlen);
      cout << kv.first << ", " << kv.second << endl;
    }

    cout << "final : " << maxlen << endl;
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
  s.longestConsecutive(v);
}
