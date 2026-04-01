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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  int dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&result) {
    if (!root)
      return 0;
    int r1 = dfs(root->left, p, q, result);
    int r2 = dfs(root->right, p, q, result);
    cout << "root: " << root->val << "r1: " << r1 << ", r2: " << r2
         << ", result is " << result << endl;
    if (result)
      return 2;
    // 代码有点啰嗦
    // 逻辑没有考虑完全, 开始没加上这一段
    // return 的值是不是空就能替代 r1, r2的返回值的效果
    if (r1 + r2 == 2) {
      result = root;
      return 2;
    }

    if (root == p || root == q) {
      if (r1 + r2 == 1) {
        result = root;
        return 2;
      } else {
        return 1;
      }
    }

    return r1 + r2;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int flag = 0;
    TreeNode *result = nullptr;
    dfs(root, p, q, result);
    return result;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
