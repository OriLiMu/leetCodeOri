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
  TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorder_map,
                int pleft, int pright, int ileft, int iright) {
    if (pleft > pright)
      return nullptr;
    int rv = preorder[pleft];
    TreeNode *root = new TreeNode(rv);
    int rootIdx = inorder_map[rv];
    int lst_size = rootIdx - ileft;
    int rst_size = iright - rootIdx;
    // 这个lst_size, rst_size的判断可以去掉, 但是去掉之后,
    // 那么这个判空的操作就交给了下一层递归函数, 这个开销就比较大
    if (lst_size) {
      root->left = dfs(preorder, inorder_map, pleft + 1, pleft + lst_size,
                       ileft, rootIdx - 1);
    }
    if (rst_size) {
      root->right = dfs(preorder, inorder_map, pleft + lst_size + 1, pright,
                        rootIdx + 1, iright);
    }

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); ++i)
      inorder_map.insert({inorder[i], i});

    return dfs(preorder, inorder_map, 0, preorder.size() - 1, 0,
               inorder.size() - 1);
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
