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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return nullptr;

    // 这个加到前面是一个技巧
    if (root == p || root == q)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    // 几种情况,
    // 当前的是匹配的. 下面有一个匹配
    // 当前的是匹配的. 下面没有匹配
    // 当前不匹配下面也不匹配
    // 当前不匹配, 下面有一个匹配
    // 当前不匹配, 下面有2个匹配
    // 这个很有意思, 看似复杂的逻辑实际上就是这三种判断
    // 简单来讲逻辑变成, 如果left-right都存在返回root, 否则, 谁存在返回谁
    //
    //
    // 后来发现这个逻辑也不用加, 这个也会被上级处理, 需要添加,
    // 不然当前点永远不会被添加, 但是这个逻辑和left-right没关系需要放到前面
    // if (root == p || root == q) // 这个时候root的值肯定上返回.
    //                             // 如果root不是最终的答案由上级调用决定
    //   return root;
    if (left && right)
      return root;
    else if (left)
      return left;
    else // 这个写法也是很有意思, 这个right本身包括了, nullptr
      return right;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
