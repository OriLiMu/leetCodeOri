#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return 0;
    sort(nums.begin(), nums.end());
    // print nums
    for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << " ";
    }
    cout << endl;
    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
      int left = 0;
      int right = nums.size() - 1;
      int lastResult = result;
      bool isLastResultSet = false;
      while (left < right) {
        if (left == i) {
          left++;
          continue;
        }
        if (right == i) {
          right--;
          continue;
        }
        int tempResult = nums[i] + nums[left] + nums[right];
        if (isLastResultSet &&
            (((target - tempResult) ^ (target - lastResult)) < 0)) {
          if (abs(target - tempResult) < abs(target - result)) {
            result = tempResult;
            break;
          }
        }
        if (target > tempResult) {
          left++;
        } else {
          right--;
        }
        lastResult = tempResult;
        isLastResultSet = true;
        if (abs(target - tempResult) < abs(target - result)) {
          result = tempResult;
        }
      }
      isLastResultSet = false;
    }
    return result;
  }
};

int main() {
  Solution s;
  int target = -2805;
  vector<int> nums = {
      13,   252,  -87,  -431, -148, 387,  -290, 572,  -311, -721, 222,  673,
      538,  919,  483,  -128, -518, 7,    -36,  -840, 233,  -184, -541, 522,
      -162, 127,  -935, -397, 761,  903,  -217, 543,  906,  -503, -826, -342,
      599,  -726, 960,  -235, 436,  -91,  -511, -793, -658, -143, -524, -609,
      -728, -734, 273,  -19,  -10,  630,  -294, -453, 149,  -581, -405, 984,
      154,  -968, 623,  -631, 384,  -825, 308,  779,  -7,   617,  221,  394,
      151,  -282, 472,  332,  -5,   -509, 611,  -116, 113,  672,  -497, -182,
      307,  -592, 925,  766,  -62,  237,  -8,   789,  318,  -314, -792, -632,
      -781, 375,  939,  -304, -149, 544,  -742, 663,  484,  802,  616,  501,
      -269, -458, -763, -950, -390, -816, 683,  -219, 381,  478,  -129, 602,
      -931, 128,  502,  508,  -565, -243, -695, -943, -987, -692, 346,  -13,
      -225, -740, -441, -112, 658,  855,  -531, 542,  839,  795,  -664, 404,
      -844, -164, -709, 167,  953,  -941, -848, 211,  -75,  792,  -208, 569,
      -647, -714, -76,  -603, -852, -665, -897, -627, 123,  -177, -35,  -519,
      -241, -711, -74,  420,  -2,   -101, 715,  708,  256,  -307, 466,  -602,
      -636, 990,  857,  70,   590,  -4,   610,  -151, 196,  -981, 385,  -689,
      -617, 827,  360,  -959, -289, 620,  933,  -522, 597,  -667, -882, 524,
      181,  -854, 275,  -600, 453,  -942, 134};
  cout << s.threeSumClosest(nums, target) << endl;
  return 0;
}
