#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
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
  void func(TreeNode *node, vector<int> &r) {
    if (!node)
      return;
    func(node->left, r);
    r.push_back(node->val);
    func(node->right, r);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> r;
    func(root, r);
    return r;
  }
};
int main() {
  Solution s;
  s.inorderTraversal(root);
}
