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
  // 错误代码
  // 1. 原因是 mid 的计算是针对 r = mid, 但是题目中不是
  // 2. 另一个原因是你等于的条件在上面, 就是说 nums[mid] 可能等于 nums[l],
  // 那么这里必须 l = mid, 不然可能丢掉值 所以 判断条件的等号, mid的计算方法和l
  // r 的赋值这三个是一体的关系, 必须对应
  // 当前这个也是错误示例
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    // 如果这里把等于也加进去, 那么就会出现死循环, 在 l = mid这里
    // 这个循环的结果, 最终结果一定是 l == r 因为 = mid 的操作一定在l r之间
    // 虽然 r = mid - 1, 但是判断条件可以推出, 这个时候最少有两个数字. 所以还是
    // r >= l- 在合理范围之内
    // 所以后面 return nums[l] or nums[r] 结果是一样的
    while (l < r) {
      mid = (l + r) / 2; // 这种计算等于必须给r, r = mid
      // 分析1:
      // 这个逻辑判断的感觉不是很好, 因为求得是最小, 如果出现大于的逻辑,
      // 整体的抛弃是逻辑上比较干净的. 但是这里加了一个等于,
      // 那么就需要强行留下来mid. 这个逻辑说到底也不能算错. 但是逻辑不干净
      //
      // 分析2:
      // 注意这个条件可能会直接卡死
      // 因为 mid = (l + r) / 2 和 l = mid
      //
      // 这个代码错误的原因在于, 判断条件模糊, 因为大于的是不要的, 等于是要得,
      // 所以你这里一个判断出来两个方向有问题
      if (nums[mid] <= nums[r]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return nums[l];
  }

  // 正确
  int findMin2(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (nums[mid] > nums[r]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return nums[r];
  }

  // 正确
  int findMin3(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (nums[mid] > nums[r]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return nums[r];
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 4, 5, 1, 2};
  // v = {3, 1};
  cout << s.findMin(v) << endl;
}
