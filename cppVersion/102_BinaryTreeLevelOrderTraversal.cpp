#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iostream>
#include <numeric>
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
    deque<TreeNode *> q;
    vector<int> v;
    vector<vector<int>> r;
    q.push_back(root);
    while (q.size()) {
      int len = q.size();
      v.clear();
      while (len--) {
        if (q.front()->left)
          q.push_back(q.front()->left);
        if (q.front()->right)
          q.push_back(q.front()->right);
        v.push_back(q.front()->val);
        q.pop_front();
      }
      r.push_back(v);
    }

    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
