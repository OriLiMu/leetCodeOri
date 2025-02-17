#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
      } else {
        return false;
      }
    }
    return true;
  }

  bool validPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
      } else {
        if (isPalindrome(s.substr(left, right - left))) {
          return true;
        } else if (isPalindrome(s.substr(left + 1, right - left))) {
          return true;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  string a = "abc";
  cout << s.validPalindrome(a) << endl;
}
