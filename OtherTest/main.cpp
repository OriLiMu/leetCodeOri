#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getPermutation(vector<int> &nums, int start) {
  if (start == nums.size() - 1) {
    for (int n : nums) {
      cout << n << ", ";
    }
    cout << endl;
  }
  for (int i = start; i < nums.size(); i++) {
    swap(nums[start], nums[i]);
    getPermutation(nums, start + 1);
    swap(nums[start], nums[i]);
  }
  for (; condition; inc - expression) {
  }

  return {};
}

int main() {
  // 初始化向量
  std::vector<int> nums = {1, 2, 3};
  getPermutation(nums, 0);

  return 0;
}
