#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    while (left <= right) {
      if (nums[mid] == target) {
        cout << mid << endl;
        break;
      } else if (nums[mid] < target) {
        left = mid + 1;
        mid = (left + right) / 2;
      } else if (nums[mid] > target) {
        right = mid - 1;
        mid = (left + right) / 2;
      }
    }
    cout << mid << endl;
    return {};
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5};
  s.searchRange(nums, 5);
  cout << "hello" << endl;
}
