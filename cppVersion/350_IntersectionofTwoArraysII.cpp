#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int l1 = nums1.size();
    int l2 = nums2.size();
    int idx1 = 0;
    int idx2 = 0;
    vector<int> result;

    while (idx1 < l1 && idx2 < l2) {
      if (nums1[idx1] > nums2[idx2]) {
        idx2++;
      } else if (nums1[idx1] < nums2[idx2]) {
        idx1++;
      } else {
        result.push_back(nums1[idx1]);
        idx1++;
        idx2++;
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> result = s.intersect(nums1, nums2);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
}
