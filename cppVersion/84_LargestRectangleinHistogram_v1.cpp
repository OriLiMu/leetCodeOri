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
    int h;
    int i;
    node() {
      h = 0;
      i = -1;
    }
    node(int pv, int pi) : h(pv), i(pi) {}
  };

  int largestRectangleArea(vector<int> &heights) {
    // 以0为分割点切割heights 然后逐个获取边界
    int start = 0, end = 0, maxv = 0;
    bool isDone = false;
    vector<node> vn(heights.size());
    vector<int> edges(heights.size(), -1);
    while (start < heights.size()) {
      while (!heights[start]) {
        start++;
        if (start == heights.size()) {
          isDone = true;
          break;
        }
      }
      if (isDone)
        break;
      end = start;
      // start 往回退一个到边界之外
      start--;
      while (end < heights.size() && heights[end])
        end++;
      // end已经超边界
      // 这里注意 start end都是超出范围的. 因为后面的应用的条件是 > or < ,
      // 不能取到边界

      // 把value和idx放到结构体里面存下来
      // 这里是end 不是 end - 1, end本来就是index
      // 这里的index搞错了
      for (int i = start + 1; i < end; ++i)
        vn[i] = node(heights[i], i);

      // 根据value排序. 这个value的值不是确定的这个需要注意
      sort(vn.begin() + start + 1, vn.begin() + end,
           [](const node &a, const node &b) { return a.h < b.h; });
      // 从最小值开始逐个计算max
      // edges 本区间中已经设置好的位置
      // 这种边界计算可以用极端的例子来算, 比如这里是否-1的问题, 可以假设start:
      // -1, end = 1, 整个的长度是1, (1 - (-1)) - 1就是我们的答案
      // 你这里使用了多个变量来处理, 那么就是考虑短期的记忆的问题
      // 也容易出错
      // 这个不用加了, 用边界来处理就行, 因为边界值已经确定了
      // edges.front() = 0, edges.back() = 0;
      for (int i = start + 1; i < end; i++) {
        node n = vn[i];
        int l = n.i - 1, r = n.i + 1;
        edges[n.i] = n.h;
        while (l > start && edges[l] == -1)
          l--;
        l++;
        while (r < end && edges[r] == -1)
          r++;
        r--;
        int tm = (r - l + 1) * n.h;
        maxv = max(tm, maxv);
      }

      start = end;
    }

    return maxv;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 4};
  // v = {0};
  // // 写几个例子就知道对不对
  v = {2, 4, 2, 0, 0, 1, 100};
  v = {0, 2, 0};
  v = {0, 1, 0, 2, 1, 0, 1, 0, 0, 0, 100, 0, 0};
  cout << s.largestRectangleArea(v);
}
