#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
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
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};
    queue<TreeNode *> q;
    vector<int> r;
    q.push(root);
    while (q.size()) {
      r.push_back(q.back()->val);
      int l = q.size();
      for (int i = 0; i < l; ++i) {
        TreeNode *tn = q.front();
        if (tn->left)
          q.push(tn->left);
        if (tn->right)
          q.push(tn->right);
        q.pop();
      }
    }

    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
