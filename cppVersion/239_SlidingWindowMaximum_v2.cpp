#include <climits>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> rst;
    for (int i = 0; i < k; i++) {
      int cur = nums[i];
      while (!dq.empty() && cur > nums[dq.back()])
        dq.pop_back();
      dq.push_back(i);
    }

    rst.push_back(nums[dq.front()]);
    for (int i = k; i < nums.size(); i++) {
      int cur = nums[i];
      // 这里没有pop front. 直接切front 也是有问题的, 因为可能还没到位置
      // 这个地方不是无限制的pop_front而是不再范围内才去pop_front
      if (dq.front() == i - k)
        dq.pop_front();
      while (!dq.empty() && cur > nums[dq.back()])
        dq.pop_back();
      dq.push_back(i);
      rst.push_back(nums[dq.front()]);
      cout << "dq:" << endl;
      for (const auto &elem : dq) {
        cout << nums[elem] << " ";
      }
      cout << endl;
    }

    return rst;
  }
};
int main() {
  // 1. 输入: nums = [1,3,-1,-3,5,3,6,7], k = 3
  // 输出: {3,3,5,5,6,7}
  // 2. 输入: nums = [1], k = 1
  // 输出: {1}
  Solution s;
  vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  // v = {2, 1, 2, 3};
  // k = 2;
  // v = {1, -1};
  // k = 1;
  vector<int> r = s.maxSlidingWindow(v, k);
  cout << "ans: " << endl;
  for (const auto &elem : r) {
    cout << elem << " ";
  }
  cout << endl;
}
