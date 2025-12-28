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
  struct node {
    int v;
    int i;
    node(int pv, int pi) : v(pv), i(pi) {}
  };

  int largestRectangleArea(vector<int> &heights) {
    // 以0为分割点切割heights 然后逐个获取边界
    int start = 0, end = 0;
    while (!heights[start])
      start++;
    end = start;
    start--;
    while (heights[end])
      end++;
    // 这里注意 start end都是超出范围的. 因为后面的应用的条件是 > or < ,
    // 不能取到边界

    // 把value和idx放到结构体里面存下来
    // 根据value排序
    // 从最小值开始逐个计算max
    // 计算完毕的值就会变成新的边界
    // 然后在根据index排序
    // 下一个需要处理的值,
    // 可以放到已经根据index排序好的数组里面确定左右边界就可以算出来对应的值
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
