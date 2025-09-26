#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  // 这个和超过int的情况没有考虑
  void dfs(TreeNode *root, unordered_map<long, long> &map, long parentSum,
           int targetSum, int &result) {
    if (!root)
      return;
    long curSum = parentSum + root->val;
    long targetNum = curSum - targetSum;
    // 这个逻辑说白了就是, 如果你当前的值就是目标值,
    // 那么你不用考虑之前的sub array的情况.
    // 只有自身不满足代码考虑之前有多少个匹配的
    // 这里理解是错误的还需要考虑, 因为 [0 -> 1] 和 [1],
    // 结果一样确实两个不同的满足条件的结果
    if (curSum == targetSum)
      result++;
    if (map.count(targetNum))
      result += map[targetNum];

    map[curSum]++;
    dfs(root->left, map, curSum, targetSum, result);
    dfs(root->right, map, curSum, targetSum, result);
    map[curSum]--;
  }

  int pathSum(TreeNode *root, int targetSum) {
    unordered_map<long, long> map;
    int result = 0;
    dfs(root, map, 0, targetSum, result);
    return result;
  }
};

int main() {
  Solution s;
  cout << "hello" << endl;
}
