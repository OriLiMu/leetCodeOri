#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    /*bool isNeg = x < 0;*/
    // int abs_x = abs(x); // 正负不影响计算
    int result = 0;
    while (x) {
      // INT_MAX is climits header file.
      // Check the link here, to know why can use INT_MAX
      // [力扣（LeetCode）](https://leetcode.cn/problems/reverse-integer/solutions/755611/zheng-shu-fan-zhuan-by-leetcode-solution-bccn)
      if (result > INT_MAX / 10 ||

          result < INT_MIN / 10) {
        return 0;
      }
      result = result * 10 + x % 10;
      x /= 10;
    }

    return result;
  }
};

int main() {
  Solution s;
  cout << s.reverse(1534236469) << endl;
  cout << s.reverse(123) << endl;
  return 0;
}
