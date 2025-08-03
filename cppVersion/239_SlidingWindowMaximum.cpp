#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    vector<int> r;
    for (int i = 0; i < k - 1; i++) {
      while (q.size() && q.back() < nums[i])
        q.pop_back();
      q.push_back(nums[i]);
    }
    for (int i = k - 1; i < nums.size(); i++) {
      while (q.size() && q.back() < nums[i])
        q.pop_back();
      q.push_back(nums[i]);
      if (i >= k && q.front() == nums[i - k])
        q.pop_front();
      r.push_back(q.front());
    }

    return r;
  }
};
int main() {
  Solution s;
  vector<int> n = {1, 3, -1, -3, 5, 3, 6, 7};
  // vector<int> n = {1, -1};
  // vector<int> n = {1};
  int k = 3;
  for (auto n : s.maxSlidingWindow(n, k)) {
    cout << n << ", ";
  }
}
