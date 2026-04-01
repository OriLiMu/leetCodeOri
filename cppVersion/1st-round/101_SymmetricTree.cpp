#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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
  TreeNode *revertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *l = revertTree(root->right);
    TreeNode *r = revertTree(root->left);
    root->left = l;
    root->right = r;
    return root;
  }

  bool CmpTwoTrees(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2)
      return true;
    else if ((!t1 && t2) || (t1 && !t2))
      return false;

    if (t1->val != t2->val)
      return false;
    return CmpTwoTrees(t1->left, t2->left) && CmpTwoTrees(t1->right, t2->right);
  }

  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    if (!root->left && !root->right)
      return true;
    else if ((!root->left && root->right) || (root->left && !root->right))
      return false;
    TreeNode *leftRvt = revertTree(root->left);
    return CmpTwoTrees(leftRvt, root->right);
  }
};

int main() {
  Solution s;
  cout << "hello" << endl;
}
