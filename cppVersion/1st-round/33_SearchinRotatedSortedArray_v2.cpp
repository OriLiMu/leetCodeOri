#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
      // cout << left << right << endl;
      mid = (left + right) / 2;
      if (left == right) {
        if (nums[left] == target) {
          return left;
        } else {
          return -1;
        }
      }
      if (nums[mid] == target) {
        return mid;
      } else if (nums[left] == target) {
        return left;
      } else if (nums[right] == target) {
        return right;
      } else if (nums[mid] > nums[left]) {
        if (target > nums[mid]) {
          left = mid + 1;
        } else { // target < nums[mid]
          if (target > nums[left]) {
            right = mid - 1;
          } else if (target < nums[left]) {
            left = mid + 1;
          } else {
            return left;
          }
        }
      } else {
        if (target < nums[mid]) {
          right = mid - 1;
        } else { // target < nums[mid]
          if (target > nums[right]) {
            right = mid - 1;
          } else if (target < nums[right]) {
            left = mid + 1;
          }
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {8};
  cout << s.search(nums, 4) << endl; //  0
  cout << s.search(nums, 5) << endl;
  cout << s.search(nums, 6) << endl;
  cout << s.search(nums, 7) << endl;
  cout << s.search(nums, 0) << endl;
  cout << s.search(nums, 1) << endl;
  cout << s.search(nums, 7) << endl;
  cout << s.search(nums, 4) << endl;
  cout << s.search(nums, 5) << endl;
  cout << s.search(nums, 8) << endl;
}
