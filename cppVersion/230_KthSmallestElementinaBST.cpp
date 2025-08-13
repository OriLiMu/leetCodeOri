#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
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
  void func(TreeNode *root, int &c, int &r, int k) {
    if (!root || c == k)
      return;

    func(root->left, c, r, k);
    if (++c == k) {
      r = root->val;
      return;
    }
    func(root->right, c, r, k);
    return;
  }

  int kthSmallest(TreeNode *root, int k) {
    int r = 0, c = 0;
    func(root, c, r, k);
    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
