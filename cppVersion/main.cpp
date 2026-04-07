#include <iostream>
#include <strings.h>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> u;
    for (auto &n : nums) {
      if (u.contains(n))
        continue;
      bool le = u.contains(n + 1);
      bool re = u.contains(n - 1);
      if (le && re) {
        // 还是这个同值的问题,
        // 当一个点原本就是单一值的时候 u[u[n-1]] 就是 u[n-1]
        // 这个会给 代码带来比较大的迷惑性.
        // 所以需要把值先存起来
        int head = u[n - 1], tail = u[n + 1];
        u[u[n - 1]] = tail;
        u[u[n + 1]] = head;
        u[n] = n;
      } else if (le) {
        u[n] = u[n + 1];
        u[u[n + 1]] = n;
      } else if (re) {
        u[n] = u[n - 1];
        // 还有一个重复值的问题, 会修改之前已经设置好的数据
        // 可能 u[n - 1] 和 u[u[n - 1]] 是一个东西. 所以需要先给 u-n 赋值
        // 这个确实特别容易出错
        u[u[n - 1]] = n;
      } else
        u[n] = n;
      cout << "n: " << n << endl;
      for (const auto &elem : u)
        cout << elem.first << "*" << elem.second << ", ";
      cout << endl;
    }

    int rst = 0;
    for (auto &kv : u)
      rst = max(rst, abs(kv.first - kv.second) + 1);
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {4, 1, 3, 2};
  v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  v = {1, 0, 1, 2};
  // 经典错误 u[u[n - 1]] == u[n - 1] 的问题
  v = {1, 3, 5, 2, 4};
  //
  v = {-6, 6, -9, -7, 0,  3, 4,  -2, 2,  -1, 9, -9, 5, -3,
       6,  1, 5,  -1, -2, 9, -9, -4, -6, -5, 6, -1, 3};
  cout << s.longestConsecutive(v) << endl;
}
