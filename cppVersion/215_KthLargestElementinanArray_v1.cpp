#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minq;
    for (auto &n : nums) {
      minq.push(n);
      if (minq.size() > k)
        minq.pop();
    }
    return minq.top();
  }
};

int main() {
  Solution s;
  int k = 3;
  vector<int> v = {3, 2, 1, 5, 6, 4};
  cout << s.findKthLargest(v, k);
}
