#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
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

TreeNode *buildTree(const string &raw) {
  if (raw.empty())
    return nullptr;

  vector<string> tokens;
  string cur;
  for (char c : raw) {
    if (c == '{' || c == '}' || c == '[' || c == ']' || c == ',') {
      if (!cur.empty()) {
        tokens.push_back(cur);
        cur.clear();
      }
    } else if (!isspace(c)) {
      cur += c;
    }
  }
  if (!cur.empty())
    tokens.push_back(cur);
  if (tokens.empty())
    return nullptr;

  TreeNode *root = new TreeNode(stoi(tokens[0]));
  queue<TreeNode *> q;
  q.push(root);
  size_t idx = 1;

  while (!q.empty() && idx < tokens.size()) {
    TreeNode *node = q.front();
    q.pop();

    if (idx < tokens.size()) {
      string &left = tokens[idx++];
      if (strcasecmp(left.c_str(), "null") != 0) {
        node->left = new TreeNode(stoi(left));
        q.push(node->left);
      }
    }
    if (idx < tokens.size()) {
      string &right = tokens[idx++];
      if (strcasecmp(right.c_str(), "null") != 0) {
        node->right = new TreeNode(stoi(right));
        q.push(node->right);
      }
    }
  }
  return root;
}

// 代码逻辑
// 1. 获取root
// 2. find `root->val` 在中序遍历中查找. 如果找到 找到的位置 - left就是
// left-tree的size, 往右面就是right-tree 的size. 所以, 前提需要知道left,
// 和right的具体数值
//   1. left-tree-size = distance - left, right-tree-size = right - distance
// 3. 判断left/right tree-size 是不是为0

class Solution {
public:
  TreeNode *func(TreeNode *&root, vector<int> &preorder, vector<int> &inorder,
                 int pre_left, int pre_right, int in_left, int in_right) {
    // 这里需要判断终止逻辑, 这个终止逻辑一开始忘写了
    // 这里有一个错误，in_left >= inorder.size()
    // if (pre_left >= preorder.size() || in_left >= preorder.size() ||
    //     pre_right < 0 || in_right < 0)
    // 这里直接判断 pre_left 和 pre_right 的大小关系会不会好一点
    // func(root->right, preorder, inorder, pre_left + dist + 1, pre_right,
    // in_left + dist + 1, in_right); 因为这里左边界的变化是 in_left + dist + 1
    if (pre_left >= preorder.size() || in_left >= inorder.size() ||
        pre_right < 0 || in_right < 0)
      return nullptr;
    // 这里有个参数判断这个就是基本的了
    // 拿到
    int rtv = preorder[pre_left], lv, rv;
    root = new TreeNode(rtv);
    // 这里的这个in_left 会不会越界
    // 这里需要 in_right + 1，因为这是函数 find 的界限
    auto it =
        find(inorder.begin() + in_left, inorder.begin() + in_right + 1, rtv);
    // if(it == inorder.begin() + ir + 1), 这一步似乎不可能找不到
    int dist = distance(inorder.begin() + in_left, it);

    // 考虑这两个值, 是否可能为负值, 不可能, 这个lt_size算错了, dist
    // 本身就是从in_left开始的距离, 这道题的关键的错误在这里
    // int lt_size = dist - in_left, rt_size = in_right - lt_size;
    // dist这个变量名称, 不是很明确, 今后要避免这种命名
    int lt_size = dist, rt_size = in_right - in_left - lt_size;
    // 这里有内存泄露, 因为每个节点只是在处理自己的时候才会new
    if (lt_size) {
      // 这里的这个 + 1的计算会不会越界, 似乎不会,
      // 这里依赖了一套包括题目限制在内的逻辑保证
      root->left = new TreeNode(preorder[pre_left + 1]);
    }
    if (rt_size)
      root->right = new TreeNode(preorder[pre_left + lt_size + 1]);
    if (root->left && dist > 0) // 如果等于零, 说明左子树已经没了
      func(root->left, preorder, inorder, pre_left + 1, pre_left + lt_size,
           in_left, in_left + dist - 1);
    if (root->right &&
        in_left + dist + 1 <=
            in_right) // 这里的dist + 1 <preorder.size() 什么意思,
                      // 这里的dist + 1 是为了检测右子树是存在的,
      // 这里的基础数值是 in_left, 所以 应该是 in_left + dist + 1 <= in_right
      // 但是你这里的代码还是有问题, dist是从in_left, 开始计算的,
      // 对比的右边界是in_right
      func(root->right, preorder, inorder, pre_left + dist + 1, pre_right,
           in_left + dist + 1, in_right);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *root;
    func(root, preorder, inorder, 0, preorder.size() - 1, 0,
         inorder.size() - 1);
    return root;
  }
};

int main() {
  Solution s;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  TreeNode *root = s.buildTree(preorder, inorder);
}
