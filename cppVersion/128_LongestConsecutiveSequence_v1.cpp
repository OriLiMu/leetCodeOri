#include <array>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
  struct nodeInfo {
    int theOtherBoundary;
    int seqInfoIdx;
  };

public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    unordered_map<int, nodeInfo>
        state; // key 当前数值, value: 另一个边界的值和对应vect的在edgeVec位置
    std::deque<std::array<int, 2>> seqVec;
    // std::deque<vector<int>> seqVec;
    unordered_set<int> alreadyInsertedElem;
    int maxIdx = 0;
    // 如果插入下一个数字, 那么, 当最后逼近到一个数字的时候, 会出现key的重合,
    // 所以插入的只能是当前的数字
    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      if (alreadyInsertedElem.find(n) != alreadyInsertedElem.end()) {
        continue;
      }
      alreadyInsertedElem.insert(n);

      if (state.find(n - 1) == state.end() &&
          state.find(n + 1) == state.end()) {
        seqVec.push_back({n, n});
        // 这里的一个错误, 这个theOtherBoundary应该是具体的数字而不是idx,
        // 这个以后需要在写名字的时候写的详细一些
        state.insert({n, {n, static_cast<int>(seqVec.size() - 1)}});
      } else if (state.find(n - 1) != state.end()) {
        if (state.find(n + 1) != state.end()) {
          int left = state[n - 1].theOtherBoundary;
          seqVec[state[n - 1].seqInfoIdx][1] = state[n + 1].theOtherBoundary;
          state[state[n + 1].theOtherBoundary].seqInfoIdx =
              state[n - 1].seqInfoIdx;
          state[state[n - 1].theOtherBoundary].theOtherBoundary =
              state[n + 1].theOtherBoundary;
          state[state[n + 1].theOtherBoundary].theOtherBoundary =
              left; // fuck the details
        } else {
          if (seqVec[state[n - 1].seqInfoIdx][1] ==
              seqVec[state[n - 1].seqInfoIdx][0]) {
            seqVec[state[n - 1].seqInfoIdx][1]++;
            state.insert({n, {n - 1, state[n - 1].seqInfoIdx}});
            state[n - 1].theOtherBoundary = n;
          } else {
            state[state[n - 1].theOtherBoundary].theOtherBoundary++;
            seqVec[state[n - 1].seqInfoIdx][1]++;
            auto node = state.extract(state.find(n - 1));
            node.key() = n;
            state.insert(std::move(node));
          }
        }
      } else {
        if (seqVec[state[n + 1].seqInfoIdx][1] ==
            seqVec[state[n + 1].seqInfoIdx][0]) {
          seqVec[state[n + 1].seqInfoIdx][0]--;
          state.insert({n, {n + 1, state[n + 1].seqInfoIdx}});
          state[n + 1].theOtherBoundary =
              n; // 这个步骤一开始也没加, 这个需要维护的变量太多了.
                 // 还是需要慎重. 可能也需要画图来做一个整个的定义
        } else {
          state[state[n + 1].theOtherBoundary].theOtherBoundary--;
          seqVec[state[n + 1].seqInfoIdx][0]--;
          auto node = state.extract(state.find(n + 1));
          node.key() = n;
          state.insert(std::move(node));
        }
      }
    }

    int r = 0;
    for (auto v : seqVec) {
      if (v[1] - v[0] > r) {
        r = v[1] - v[0];
      }
    }

    return ++r;
  }
};
int main() {
  Solution s;
  // vector<int> nums = {100, 4, 200, 1, 3, 2};
  // vector<int> nums = {-7, -1, 3,  -9, -4, 7, -3, 2, 4,
  //                     9,  4,  -9, 8,  -7, 5, -1, -7};
  // vector<int> nums = {-7, -1, 3, 2, 4, 4, 5};
  // vector<int> nums = {1, 0, 1, 2};
  vector<int> nums = {-4, -1, 4,  -5, 1, -6, 9,  -6, 0, 2, 2, 7,
                      0,  9,  -3, 8,  9, -2, -6, 5,  0, 3, 4, -2};
  cout << s.longestConsecutive(nums) << endl;
}
