#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0) {
      return {-1, -1};
    }
    // find it
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    int target_idx = 0;
    int direction = -1;
    while (left <= right) {
      // cout << left << "," << right << endl;
      if (left == right) {
        if (nums[left] != target) {
          // cout << "error" << endl;
          return {-1, -1};
        } else {
          target_idx = left;
          break;
        }
      }

      mid = (left + right) / 2;
      if (nums[mid] == target) {
        target_idx = mid;
        break;
      } else if (nums[mid] > target) {
        direction = -1;
        right = max(mid - 1, 0);
      } else {
        direction = -1;
        left = min(mid + 1, static_cast<int>(nums.size() - 1));
      }
    }

    // cout << "left" << left << ", " << right << endl;

    // to left
    left = 0;
    right = target_idx;
    int left_edge_idx = -1;
    while (left <= right) {
      if (right == 0) {
        left_edge_idx = 0;
        break;
      }
      mid = (left + right) / 2;
      if (mid - 1 >= 0 && nums[mid] == target && nums[mid - 1] < target) {
        left_edge_idx = mid;
        break;
      }
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] == target) {
        right = max(0, mid - 1);
      }
    }

    left = target_idx;
    right = nums.size() - 1;
    int right_edge_idx = -1;

    while (left <= right) {
      if (left == nums.size() - 1) {
        right_edge_idx = nums.size() - 1;
        break;
      }
      mid = (left + right) / 2;
      if (mid + 1 < nums.size() && nums[mid] == target &&
          nums[mid + 1] > target) {
        right_edge_idx = mid;
        break;
      }
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] == target) {
        left = min(static_cast<int>(nums.size() - 1), mid + 1);
      }
    }

    cout << "left edge" << left_edge_idx << " " << right_edge_idx << endl;
    return {left_edge_idx, right_edge_idx};
  }
};
int main() {
  // vector<int> nums = {5, 7, 7, 8, 8, 8, 10};
  vector<int> nums = {};
  Solution s;
  vector<int> r = s.searchRange(nums, 10);
  // r = s.searchRange(nums, 5);
  // r = s.searchRange(nums, 7);
  // r = s.searchRange(nums, 10);
  // r = s.searchRange(nums, 0);
  // r = s.searchRange(nums, 8);
}
