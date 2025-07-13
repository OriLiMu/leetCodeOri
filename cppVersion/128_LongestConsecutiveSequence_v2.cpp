#include <future>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int r = 1;
    int left = 0;
    int right = 0;
    unordered_map<int, int> edgeMap;
    for (auto n : nums) {
      if (edgeMap.count(n))
        continue;
      bool hasL = (edgeMap.find(n - 1) != edgeMap.end());
      bool hasR = (edgeMap.find(n + 1) != edgeMap.end());
      if (!hasL && !hasR) {
        edgeMap.insert({n, n});
      } else if (hasL && hasR) {
        left = edgeMap[n - 1];
        right = edgeMap[n + 1];
        edgeMap[left] = right;
        edgeMap[right] = left;
        edgeMap.insert({n, n}); // 这个值可以说是典中典, 如果设置成0,
                                // 那么就可能出现最大差值, 所以只能设置为n
      } else if (hasL) {
        left = edgeMap[n - 1];
        right = n;
        edgeMap.insert({n, left});
        edgeMap[left]++;
      } else {
        left = n;
        right = edgeMap[n + 1];
        edgeMap.insert({n, right});
        edgeMap[right]--;
      }

      if (right - left + 1 > r)
        r = right - left + 1;
    }

    return r;
  }
};
int main() {
  Solution s;
  // vector<int> nums = {100, 4, 200, 1, 3, 2};
  // vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  vector<int> nums = {-6, 6, -9, -7, 0,  3, 4,  -2, 2,  -1, 9, -9, 5, -3,
                      6,  1, 5,  -1, -2, 9, -9, -4, -6, -5, 6, -1, 3};
  cout << s.longestConsecutive(nums) << endl;
}
