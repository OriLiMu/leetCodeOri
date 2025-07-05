#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = nums.size() / 2;
    if (left == right) {
      if (target == nums[0]) {
        return 0;
      }
      return -1;
    }
    while (left <= right) { // 这里应该是 <= 不然的话有一个数字验证不到
      mid = (left + right) / 2;
      cout << left << right << mid << endl;
      if (nums[mid] > target) {
        if (target < nums[left]) {
          left = mid + 1;
        } else if (target > nums[left]) {
          right = mid - 1;
        } else {
          return left; // 这里应该是left之前写成了mid
        }
      } else if (nums[mid] < target) { // 这个里面也应该分类讨论
        if (target < nums[right]) {
          left = mid + 1;
        } else if (target > nums[right]) {
          right = mid - 1;
        } else {
          return right;
        }
      } else {
        return mid;
      }
    }

    return -1;
  }
};
int main() {
  Solution s;
  vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
  cout << s.search(nums, 8) << endl;
  // 一个数字的情况没考虑到
  // 注意
  // 整体的逻辑还是没考虑清楚, 应该想的是, mid的位置才是关键,
  // 这个代码逻辑是有问题的
}
