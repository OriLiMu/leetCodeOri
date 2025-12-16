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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // 两个数组的长度都有可能等于0,但是它们的和大于等于1,所以至少有一个是有长度的
    // 所以比较一下两个数组的长短然后处理非常关键
    int l = 0, r = nums1.size() - 1;
    // 第1个难点就是合法值的判断,是否有一个向量是长度为0
    // 如果你无法暂时找到比较简洁的代码,那么直接就分情况讨论就好了
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
