#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstddef>
#include <future>
#include <iostream>
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
  bool func_recur(TreeNode *root, long lo, long hi) {
    if (!root)
      return true;
    if (root->val <= lo || root->val >= hi)
      return false;
    return func_recur(root->left, lo, (long)root->val) &&
           func_recur(root->right, (long)root->val, hi);
  }

  bool isValidBST(TreeNode *root) {
    return func_recur(root, LONG_MIN, LONG_MAX);
  }
};

int main() {
  Solution s;
  string str = "[3,1,5,0,2,4,6]";
  str = "[3,1,5]";
  TreeNode *t = buildTree(str);
  cout << s.isValidBST(t) << endl;
}
