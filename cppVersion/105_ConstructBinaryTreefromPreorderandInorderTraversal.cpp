#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
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
  TreeNode *func(vector<int> &preorder, vector<int> &inorder, int pre_start,
                 int in_start) {
    if (pre_start >= preorder.size() ||
        in_start >= inorder.size()) // 这里的in_start是否需要判断
      return nullptr;
    // 1. preorder的第一个就是 root
    int root_value = preorder[pre_start];
    TreeNode *root = new TreeNode(root_value);
    // 2. 然后在inorder 里面搜索这个 root. 这样可以得出left subtree的大小,
    // 有可能是0
    auto it = find(inorder.begin() + in_start, inorder.end(), root_value);
    // 根据条件, 必然能找到, 但是这时候还不能确定 left-subtree是存在的,
    // 还需要确定大小
    int dist = distance(inorder.begin(), it);
    int left_subtree_size = 0;
    if (dist <= in_start)
      root->left = nullptr;
    else {
      left_subtree_size = dist - in_start;
      root->left = new TreeNode(preorder[pre_start + 1]);
    }

    // 3. 最后在preorder里面用root的位置+ left-subtree.size() + 1就是right的位置
    root->right = nullptr;
    int right_idx = pre_start + left_subtree_size + 1;
    if (right_idx < preorder.size())
      root->right = new TreeNode(preorder[right_idx]);

    func(preorder, inorder, pre_start + 1, in_start);
    func(preorder, inorder, right_idx, in_start + 1);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (!preorder.size())
      return nullptr;
    return func(preorder, inorder, 0, 0);
  }
};

int main() {
  Solution s;
  vector<int> preorder = {1, 2, 3};
  vector<int> inorder = {2, 1, 3};
  TreeNode *root = s.buildTree(preorder, inorder);
  cout << "hello" << endl;
}
