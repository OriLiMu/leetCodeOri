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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  int dfs(TreeNode *root, int &result) {
    if (!root)
      return 0;
    int lv = max(0, dfs(root->left, result));
    int rv = max(0, dfs(root->right, result));
    result = max(result, lv + rv + root->val);
    return max(max(lv + root->val, rv + root->val), 0);
  }

  int maxPathSum(TreeNode *root) {
    int result = root->val;
    dfs(root, result);
    return result;
  }
};

int main() {
  Solution s;
  cout << "hello" << endl;
}
