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
    int l3 = rl;
    int s1 = 0, s2 = 0;
    bool isOdd = (l1 + l2) % 2 == 0 ? false : true;
    while (rl > 0) {
      if ((nums1.size() - s1) < (nums2.size() - s2)) {
        swap(nums1, nums2);
        swap(s1, s2);
      }

      if (s2 == nums2.size()) {
        s1 += rl;
        if (isOdd)
          return nums1[s1];
        else
          return (nums1[s1] + nums1[s1 - 1]) / 2.0;
      }

      // 还是有可能一半的 rl比l2的总长度还要长
      // 要截取的长度是整个长度的1/4, 那么长的数组一定是满足在长数组之内的,
      // 不然长数组和短数组相加的长度就不够了
      // 这里需要考虑短的不夠的情况
      // ====
      // 这里有一个关键的理解问题, 就是切割线的坐标表示.
      // 切割线的本质是两个坐标之间的数字. 所以如何定义是一个问题
      // ====
      //
      // 发现一个问题, sp1 是表示对应坐标前面是切线, 还是后面是切线
      // 无论前后, 都需要考虑越界的问题. 如果是前面是切线,
      // 那么如果切线在最开始的地方. sp 就是-1
      // 发现在后面逻辑容易处理一点,
      // 在前面计算算式更清楚明确一点, 我这里采用在前面
      // 我用了"在前面的" 的处理方式, 发现很容易出错,
      // 因为跟我的默认的理解方式冲突
      // 修改成: 在后面. 那么这样s1, s2 应该开始等于-1
      // 所以有一个问题, 就是 数组长度, 切割线位置 和
      // 起始坐标的关系是一个重要问题
      // 特例的设置, 一开始是-1, 如果需要距离1的地方设置一个分割线,
      // 那么这个对应的坐标是0, 如果把坐标对应的元素的后面的位置作为分割线的位置
      // 我们考虑起始坐标为1 的情况. 如果距离是2,
      // 因为起始的状态1的分割线就是在后面已经包括了一个长度, 所以如果距离是2,
      // 这个位置在2的后面,
      // 就是需要注意开始的这个点什么也不做就已经包括了一个长度 那么可以得出,
      // 长度对应的坐标应该是-1
      // 这里感觉我在问题中设置的变量不是很合适.迷惑的地方比较多.概念穿插
      // 这样理解我感觉, 概念的定义上就非常的复杂了
      int sp1 = s1 + rl - rl / 2 - 1,
          sp2 = s2 + rl / 2 - 1; // sp1 把长的断点留给自己
      if (nums2.size() - s2 < rl / 2) {
        // 还是明确一下切割点是怎么算出来的
        // 这里还需要-1吗? 需要 s1 默认包括一个长度
        sp1 = s1 + rl - (nums2.size() - s2) - 1;
        sp2 = nums2.size() - 1;
        if (nums2[sp2] > nums1[sp1]) {
          s1 = sp1 + 1;
          rl = nums2.size() - s2;
        } else {
          // 因为 sp2后面这个点已经失败了
          s2 = sp2 + 1;
          rl -= nums2.size() - s2;
        }
      } else {
        if (nums1[sp1] > nums2[sp2]) {
          s2 = sp2 + 1;
          // 这个地方, 有问题, 可能rl = 1 那么 rl / 2 = 0, 那你这里数据没有迭代
          rl = rl - max(1, rl / 2);
        } else {
          s1 = sp1 + 1;
          rl = rl / 2;
        }
      }
    }

    cout << "s1:" << s1 << ", s2:" << s2 << endl;
    // 这个时候s过了一位, 如果想找到前一位需要-1, 这样还得判断s1是不是0
    // 这个奇数是对的.
    if (isOdd)
      return nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2];
    else
      // 这个式子是错的, s1, s2都是过位的都是后半段的index
      // return (nums1[s1] + nums2[s2]) / 2.0;
      return (min(nums1[s1], nums2[s2]) + max(nums1[s1 - 1], nums2[s2 - 1])) /
             2.0;
  }
};

int main() {
  Solution s;
  vector<int> v1 = {1, 2};
  vector<int> v2 = {3, 4};
  cout << "Answer is: " << s.findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
