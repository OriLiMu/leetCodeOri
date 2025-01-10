#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
  int getTargetStateByChar(char c) {
    if (c == ' ') {
      return 0;
    } else if (isdigit(c)) {
      return 1;
    } else if (c == '-' || c == '+') {
      return 2;
    } else {
      return 3;
    }
    return -1;
  }

  int myAtoi(string s) {
    unordered_map<string, vector<string>> stateTable = {
        {"s_start", {"s_start", "s_number", "s_sign", "s_end"}},
        {"s_number", {"s_end", "s_number", "s_end", "s_end"}},
        {"s_sign", {"s_end", "s_number", "s_end", "s_end"}},
        {"s_end", {"s_end", "s_end", "s_end", "s_end"}}};
    string curState = "s_start";
    string nextState = "";
    long long result = 0;
    int signMark = 1;
    for (char c : s) {
      int targetState = getTargetStateByChar(c);
      curState = stateTable[curState][targetState];
      if (curState == "s_start") {
        continue;
      } else if (curState == "s_number") {
        result = 10 * result + c - '0';
        if (signMark * result > INT_MAX) {
          return INT_MAX;
        }
        if (signMark * result < INT_MIN) {
          return INT_MIN;
        }
      } else if (curState == "s_sign") {
        if (c == '-') {
          signMark = -1;
        }
      } else if (curState == "s_end") {
        break;
      }
    }

    return signMark * result;
  }
};

int main() {
  Solution s;
  cout << s.myAtoi("2147483646") << endl;
  return 0;
}
