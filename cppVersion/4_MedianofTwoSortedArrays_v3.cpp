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
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  // 这个好像是错误的思路. 我的想法是用二分法在a上去做中点
  // 没有错误只是思路不是我原本的二分法思路
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int l1 = nums1.size(), l2 = nums2.size();
    int rl = (l1 + l2) / 2;
    int s1 = 0, s2 = 0;
    bool isOdd = (l1 + l2) % 2 != 0;
    while (rl > 0) {
      if ((nums1.size() - s1) < (nums2.size() - s2)) {
        swap(nums1, nums2);
        swap(s1, s2);
      }

      // 这个地方能不能去掉
      // 你这个逻辑有一个把元素顶出去的操作, 这个操作本身就有可能造成数组越界
      // 这个逻辑有问题, 你在人为的制造问题
      if (s2 == nums2.size()) {
        // 这里的理解就是还需要切掉几个
        // 如果需要切掉一个, 那么当前的这个需要切掉, 也就是往前走一个位置
        // 就是 s1 += rl
        s1 += rl;
        if (isOdd)
          return nums1[s1];
        else
          return (nums1[s1] + nums1[s1 - 1]) / 2.0;
      }

      l2 = min((int)nums2.size() - s2, rl / 2);
      l1 = rl - l2;

      // 这里的这个-1的问题还是需要注意
      // 还是下标的边界问题
      if (nums1[s1 + max(0, l1 - 1)] > nums2[s2 + max(l2 - 1, 0)]) {
        s2 += max(l2, 1);
        rl -= max(l2, 1); // 这里是推进循环的关键步骤, 这个变量l2可能为0
      } else {
        s1 += max(l1, 1);
        rl -= max(l1, 1);
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
  v1 = {};
  v2 = {1, 2, 4, 5};
  v1 = {1, 3};
  v2 = {2};
  cout << "Answer is: " << s.findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
