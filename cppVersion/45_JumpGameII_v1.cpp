#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;
    int s = 0, e = 1, r = 1;
    vector<int> v(nums.size());
    // 这个范围需要注意
    // 逻辑没问题, 但是参考 AcWin个的代码, 人家的更舒服. 就是针对一个变量e去修改
    // 你这个代码有点两头堵, 同时维护s, e, 主要维护e, 这个动作比较大, 次要维护s
    // 这样整体的逻辑比较清楚
    while (e < nums.size()) {
      while (nums[s] + s < e) {
        if (!v[++s])
          v[s] = v[s - 1] + 1;
      }
      v[e] = v[s] + 1;
      e++;
    }

    return v.back();
  }
};
int main() {
  Solution s;
  vector<int> v = {2, 3, 1, 1, 4};
  v = {2, 3, 0, 1, 4};
  cout << s.jump(v);
}
