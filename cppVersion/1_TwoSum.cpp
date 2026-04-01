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
        return {i, u[target - nums[i]]};
      else
        u.insert({nums[i], i});
    }

    return {};
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 7, 11, 15};
  int target = 9;
  vector<int> t = s.twoSum(v, target);
  cout << t[0] << ", " << t[1] << endl;
}
