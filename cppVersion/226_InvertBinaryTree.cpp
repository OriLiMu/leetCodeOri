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

TreeNode *buildTree(const std::vector<int> &nodes) {
  if (nodes.empty() || nodes[0] == -1)
    return nullptr; // -1 表示空节点

  TreeNode *root = new TreeNode(nodes[0]);
  std::queue<TreeNode *> q;
  q.push(root);

  size_t i = 1;
  while (!q.empty() && i < nodes.size()) {
    TreeNode *current = q.front();
    q.pop();

    // 左子节点
    if (i < nodes.size() && nodes[i] != -1) {
      current->left = new TreeNode(nodes[i]);
      q.push(current->left);
    }
    i++;

    // 右子节点
    if (i < nodes.size() && nodes[i] != -1) {
      current->right = new TreeNode(nodes[i]);
      q.push(current->right);
    }
    i++;
  }

  return root;
}

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    // 经典错误
    TreeNode *l = invertTree(root->right); // 先修改了左子树
    TreeNode *r =
        invertTree(root->left); // 此时 root->left 已经是原来的右子树了
    // root->left = r;
    // root->right = l; // 你这个左右自己给自己整绕了
    root->left = l;
    root->right = r;

    return root;
  }
};
int main() {
  Solution s;
  vector<int> nodes = {4, 2, 7, 1, 3, 6, 9};
  TreeNode *t = buildTree(nodes);
  s.invertTree(t);
}
