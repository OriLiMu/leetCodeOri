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
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    vector<int> cntMap(50);
    // 排序的index vector size是多少.
    // 这个index vector记录什么? 记录前k/m个, 排好顺序的index
    // 如果是k, 后面如果来了第k+1个数字就会超范围 , 觉得自己想蒙了
    // 我觉得第一步还是抛开, 代码的实际语法限制, 先明确处理过程
    for (int i = 0; i < k; ++i)
      cntMap[nums[i]]++;
    sort()
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
