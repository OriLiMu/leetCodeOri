#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <ranges>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  void rec(vector<int> &allNums, int startIndex, vector<int> &curRes,
           vector<vector<int>> &finallRes) {
    // cout << "curRes" << endl;
    // for (auto &n : curRes) {
    //   cout << n << ", ";
    // }
    // cout << endl;
    //
    // 这里是 allNums.size() 还是 allNums.size() - 1
    // 这是使用size() - 1的方式，代码存在某种程度的重复
    // curRes.push_back(allNums.back());
    // finallRes.push_back(curRes);
    // curRes.pop_back();
    //
    if (startIndex == allNums.size()) {
      finallRes.push_back(curRes);
      cout << "allNums" << endl;
      for (const auto &elem : allNums) {
        cout << elem << " ";
      }
      cout << endl;
      return;
    }
    for (int i = startIndex; i < allNums.size(); ++i) {
      swap(allNums[startIndex], allNums[i]);
      curRes.push_back(allNums[startIndex]);
      rec(allNums, startIndex + 1, curRes, finallRes);
      // 这道题的很有意思的一点就是需要换回
      // swap(allNums[startIndex], allNums[i]);
      curRes.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> curRes;
    vector<vector<int>> res;
    rec(nums, 0, curRes, res);
    return res;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> r = s.permute(nums);
  for (auto &v : r) {
    for (auto &n : v) {
      cout << n << ", ";
    }
    cout << endl;
  }
}
