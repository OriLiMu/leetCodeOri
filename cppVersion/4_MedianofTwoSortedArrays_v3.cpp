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

      int sp1 = s1 + rl - rl / 2 - 1;
      // sp1 把长的断点留给自己, 这个地方很容易错
      int sp2 = s2 + max(rl / 2 - 1, 0);

      l2 = min((int)nums2.size() - s2, rl / 2);
      l1 = rl - l2;

      // 使用了大量的变量
      // 分割线的index处理
      if (nums2.size() - s2 < rl / 2) {
        sp1 = s1 + rl - (nums2.size() - s2) - 1;
        sp2 = nums2.size() - 1;
        if (nums2[sp2] > nums1[sp1]) {
          s1 = sp1 + 1;
          rl = nums2.size() - s2;
        } else {
          rl -= nums2.size() - s2;
          s2 = sp2 + 1;
        }
      } else {
        if (nums1[sp1] > nums2[sp2]) {
          s2 = sp2 + 1;
          rl = rl - max(1, rl / 2);
        } else {
          s1 = sp1 + 1;
          rl = rl / 2;
        }
      }
    }

    // 这里的处理主要的内容还是对s1, s2有效性的判断.
    // 能不能在上面处理这个有效性的问题
    if (isOdd) {
      if (s1 == nums1.size())
        return nums2[s2];
      if (s2 == nums2.size())
        return nums1[s1]; // 这个地方手误了
      return nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2];
    } else {
      // 这个式子是错的, s1, s2都是过位的都是后半段的index
      // return (nums1[s1] + nums2[s2]) / 2.0;
      // 这里需要验证数据有效性
      // 非常麻烦
      if (s1 == nums1.size()) {
        if (s2 == 0)
          return (nums1[s1 - 1] + nums2[s2]) / 2.0;
        return (max(nums1[s1 - 1], nums2[s2 - 1]) + nums2[s2]) / 2.0;
      } else if (s2 == nums2.size()) {
        if (s1 == 0)
          return (nums2[s2 - 1] + nums1[s1]) / 2.0;
        return (max(nums1[s1 - 1], nums2[s2 - 1]) + nums1[s1]) / 2.0;
      }

      if (s1 == 0 && s2 == 0)
        return (nums1[s1] + nums2[s2]) / 2.0;
      else if (s1 == 0 && s2 != 0)
        return (min(nums1[s1], nums2[s2]) + nums2[s2 - 1]) / 2.0;
      else if (s1 != 0 && s2 == 0)
        return (min(nums1[s1], nums2[s2]) + nums1[s1 - 1]) / 2.0;
      return (min(nums1[s1], nums2[s2]) + max(nums1[s1 - 1], nums2[s2 - 1])) /
             2.0;
    }
  }
};

int main() {
  Solution s;
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
  v1 = {};
  v2 = {1, 2, 4, 5};
  cout << "Answer is: " << s.findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
