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

      // 这里生成多个判断的原因有这几个.
      // 1. 人为的设置了越界的情况
      // 2. 你的停止的点是在while循环中确定的, 应该在这个时候马上就设置检查.
      // 流到下一步更加的麻烦
      // 3. 没有设置剩余长度为1的检查, 这是导致你的代码中频繁的出现max设置的问题
      // if (nums1[s1 + max(0, l1 - 1)] > nums2[s2 + max(l2 - 1, 0)]) {
      // 4. 另一个问题, 就是你这里是混用了奇数和偶数的逻辑.
      // 所以后续的代码判断复杂
      //
      // 到这里的情况是: 你计算而来的重点的端点值,
      // 必须经过端点的验证判断才能使用
      // 优势就是我的这个代码比acwing的快乐一倍,
      // 因为我能从一次的二分法中计算出结果, acwing对于偶数需要计算两次
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
