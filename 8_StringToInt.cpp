#include <cctype>
#include <climits>
#include <cmath>
#include <functional>
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
    } else if (isalpha(c)) {
      return 3;
    }
    return -1;
  }

  int myAtoi(string s) {
    unordered_map<string, vector<string>> stateTable = {
        {"s_start", {"s_start", "s_number", "s_number", "s_end"}},
        {"s_number", {"s_end", "s_number", "s_end", "s_end"}},
        {"s_sign", {"s_end", "s_number", "s_end", "s_end"}},
        {"s_end", {"s_end", "s_end", "s_end", "s_end"}}};
    string curState = "s_start";
    string nextState = "";
    int result = 0;
    int signMark = 1;
    for (char c : s) {
      int targetState = getTargetStateByChar(c);
      if (targetState == -1) {
        cout << "ERROR state:" << c << endl;
      }
      curState = stateTable[curState][targetState];
      if (curState == "s_start") {
        continue;
      } else if (curState == "s_number") {
        result += 10 * result + c - '0';
      } else if (curState == "s_sign") {
        if (c == '-') {
          signMark = true;
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
  return 0;
}
