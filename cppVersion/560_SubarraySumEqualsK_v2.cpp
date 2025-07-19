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
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> preSumMap = {{0, 1}};
    int curPreSum = 0, result = 0;
    for (auto n : nums) {
      curPreSum += n;
      if (preSumMap.find(curPreSum - k) != preSumMap.end())
        result += preSumMap[curPreSum - k];
      preSumMap[curPreSum]++;
    }
    return result;
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 1, 1};
  int k = 2;
  cout << s.subarraySum(v, k) << endl;
}
