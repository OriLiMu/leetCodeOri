#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
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
  TreeNode *toBST(vector<int> &nums, int left, int right) {
    if (left > right)
      return nullptr;
    // int mid = (left + right) / 2;
    int mid = left + (right - left) / 2; // 防溢出写法
    auto *curNode = new TreeNode(nums[mid]);
    curNode->left = toBST(nums, left, mid - 1);
    curNode->right = toBST(nums, mid + 1, right);
    return curNode;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return toBST(nums, 0, nums.size() - 1);
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
