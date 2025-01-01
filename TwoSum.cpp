#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hashMap;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int curNum = nums[i];
      int targetAddend = target - nums[i];
      if (hashMap.count(targetAddend)) {
        return vector<int>({i, hashMap[targetAddend]});
      }
      hashMap.insert({curNum, i});
    }

    return res;
  }
};
