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
  // 几个变量需要维护?
  // 在那些状态下维护
  // 这个函数如果不考虑递归那么处理的问题就是, 考虑当前所选数字的,
  // 所有下一个情况, 这样逻辑就完善了
  // startIdx是当前的可选项目, 从哪里开始
  void func(int leftLen, int startIdx, vector<int> &cur, vector<int> &nums,
            vector<vector<int>> &result) {
    // if (!leftLen ||
    //     startIdx >=
    //         nums.size()) { // 这里虽然考虑了剩余参数过剩的问题,
    //                        //
    //                        也引入了数字还没选够但是startIdx已经超过size的情况
    if (!leftLen) {
      result.push_back(cur);
      // cur.pop_back(); // 经典的错误 这里导致了重复的pop_back, 会引发空vector
      // pop_back
      return;
    }

    for (int j = startIdx; j < nums.size(); ++j) {
      cur.push_back(nums[j]);
      func(leftLen - 1, j + 1, cur, nums, result);
      cur.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result = {{}};
    vector<int> cur;
    int startIdx = 0;
    for (int i = 0; i < nums.size(); ++i)
      func(i + 1, 0, cur, nums, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> r = s.subsets(nums);
  cout << "Total subsets: " << r.size() << endl;
  for (auto &v : r) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
      if (i > 0)
        cout << ", ";
      cout << v[i];
    }
    cout << "]" << endl;
  }
}
