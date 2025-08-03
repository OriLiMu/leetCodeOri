#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <queue>
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

TreeNode *buildTree(const vector<int> &nums) {
  if (nums.empty() || nums[0] == INT_MIN)
    return nullptr;
  TreeNode *root = new TreeNode(nums[0]);
  queue<TreeNode *> q;
  q.push(root);
  size_t i = 1; // 当前待处理的子节点位置
  while (!q.empty() && i < nums.size()) {
    TreeNode *cur = q.front();
    q.pop();
    /* left */
    if (i < nums.size() && nums[i] != INT_MIN) {
      cur->left = new TreeNode(nums[i]);
      q.push(cur->left);
    }
    ++i;
    /* right */
    if (i < nums.size() && nums[i] != INT_MIN) {
      cur->right = new TreeNode(nums[i]);
      q.push(cur->right);
    }
    ++i;
  }
  return root;
}

class Solution {
public:
  int maxDepth(TreeNode *root, int &maxDiameter) {
    if (!root)
      return 0;
    int leftDepth = maxDepth(root->left, maxDiameter);
    int rightDepth = maxDepth(root->right, maxDiameter);
    maxDiameter = max(leftDepth + rightDepth, maxDiameter);
    return max(leftDepth, rightDepth) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    int result = 0;
    maxDepth(root, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v = {4,       -7, -3,      INT_MIN, INT_MIN, -9, -3,      9,
                   -7,      -4, INT_MIN, 6,       INT_MIN, -6, -6,      INT_MIN,
                   INT_MIN, 0,  6,       5,       INT_MIN, 9,  INT_MIN, INT_MIN,
                   -1,      -4, INT_MIN, INT_MIN, INT_MIN, -2};
  TreeNode *t = buildTree(v);

  cout << s.diameterOfBinaryTree(t) << endl;
}
