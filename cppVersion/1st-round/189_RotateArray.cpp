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

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    int count = gcd(k, n); // 这里的gcd, 和下面的start < count 是精髓
    for (int start = 0; start < count; ++start) {
      int current = start;
      int prev = nums[start];
      do {
        int next = (current + k) % n;
        swap(nums[next], prev);
        current = next;
      } while (start != current);
      cout << "begin" << endl;
      for (int n : nums) {
        cout << n << ", ";
      }
      cout << endl;
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  s.rotate(nums, k);
  for (auto n : nums) {
    cout << n << ", ";
  }
}
