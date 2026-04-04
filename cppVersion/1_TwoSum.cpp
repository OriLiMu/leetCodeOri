#include <iostream>
#include <strings.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> u;
    for (int i = 0; i < nums.size(); ++i) {
      if (u.find(target - nums[i]) != u.end())
        return {i, nums[target - nums[i]]};
      else
        u.insert({nums[i], i});
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
