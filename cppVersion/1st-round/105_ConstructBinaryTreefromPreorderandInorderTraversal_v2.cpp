#include <algorithm>
#include <climits>
#include <cmath>
#include <complex>
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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr,
                int il, int ir) {
    if (pl > pr || il > ir)
      return nullptr;
    // create root node
    int rv = preorder[pl];
    TreeNode *root = new TreeNode(rv);
    // check if left subtree exist
    auto it = find(inorder.begin() + il, inorder.begin() + ir, rv);
    int l_size = distance(inorder.begin() + il, it);
    int r_size = pr - pl + 1 - l_size - 1;
    if (l_size) {
      root->left = dfs(preorder, inorder, pl + 1, pl + l_size, il, il + l_size);
    }
    if (r_size) {
      root->right =
          dfs(preorder, inorder, pl + l_size + 1, pr, il + l_size + 1, ir);
    }

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return dfs(preorder, inorder, 0, preorder.size() - 1, 0,
               inorder.size() - 1);
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
