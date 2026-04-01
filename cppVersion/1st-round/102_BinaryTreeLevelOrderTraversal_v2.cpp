#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iostream>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {};
    vector<vector<int>> r;
    deque<TreeNode *> dq;
    int len = 1;
    dq.push_back(root);
    while (len) {
      int tl = len;
      vector<int> tmp;
      for (int i = 0; i < tl; ++i) {
        tmp.push_back(dq.front()->val);
        if (dq.front()->left) {
          dq.push_back(dq.front()->left);
          len++;
        }
        if (dq.front()->right) {
          dq.push_back(dq.front()->right);
          len++;
        }
        dq.pop_front();
        len--;
      }
      r.push_back(tmp);
    }

    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
