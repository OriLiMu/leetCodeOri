#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
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

class Solution {
public:
  void func(TreeNode *root, TreeNode *cur) {
    if (!root)
      return;
    cur = cur->right = root;
    func(root->left, cur);
    func(root->right, cur);
    root->right = root->left;
    root->left = nullptr;
  }
  void flatten(TreeNode *root) {
    if (!root)
      return;
    TreeNode dummy(0), *cur = &dummy;
    func(root, cur);
  }
};
int main() {
  Solution s;
  string str = "[1,2,5,3,4,null,6]";
  TreeNode *root = buildTree(str);
  s.flatten(root);
}
