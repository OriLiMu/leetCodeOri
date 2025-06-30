#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> savedValueDict;
    for (int i = 0; i < nums.size(); i++) {
      if (savedValueDict.find(nums[i]) != savedValueDict.end()) {
        if (abs(i - savedValueDict[nums[i]]) <= k)
          return true;
        savedValueDict[nums[i]] = i;
      } else {
        savedValueDict.emplace(nums[i], i);
      }
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  int k = 2;
  cout << s.containsNearbyDuplicate(nums, k) << endl;
}
