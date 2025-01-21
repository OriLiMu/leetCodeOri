// 18ms beat 70%
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    struct charInfoSt {
        int index;
        char c;
    };
    struct stateSt {
        string state;
        int leftBoundary;
    };

public:
    int longestValidParentheses(string s) {
        vector<int> result{-1, -1};
        stack<charInfoSt> matchInfoStk;
        vector<stateSt> stateVec(s.size(), {"Pending", -1});
        unordered_map<int, int> boundaryMap;
        vector<int> resultIndex = {0, 0};
        for (int i = 0; i < s.size(); i++) {
            char curChar = s[i];
            if (s[i] == '(') {
                matchInfoStk.push({i, curChar});
            } else { // 下面都是右括号的判断
                if (!matchInfoStk.empty()) {
                    charInfoSt curMatchLeftState =
                            matchInfoStk
                                    .top(); // 一定是 '(', ')' 要么不会插入, 要么直接弹出来
                    matchInfoStk.pop();
                    stateSt curElem;
                    stateSt leftOfCurLeft = stateVec[curMatchLeftState.index - 1];
                    stateSt curLeft = stateVec[curMatchLeftState.index];

                    int curLeftBoundary = -1;
                    if (curMatchLeftState.index > 0) { // 当前不是第一个
                        if (leftOfCurLeft.state == "Valid") {
                            curLeftBoundary = leftOfCurLeft.leftBoundary;
                        } else {
                            curLeftBoundary = curMatchLeftState.index;
                        }
                    } else { // 当前的left 是第一个
                        curLeftBoundary = 0;
                    }

                    curLeft = {"Valid", curLeftBoundary};
                    stateVec[i] = {"Valid", curLeftBoundary};
                    if (i - curLeftBoundary > result[1] - result[0]) {
                        result = {curLeftBoundary, i};
                    }
                } else {
                    stateVec[i] = {"Invalid", -1};
                }
            }
        }
        if (result[1] - result[0] == 0) {
            return 0;
        } else {
            return result[1] - result[0] + 1;
        }
    }
};

int main() {
//    Solution s;
//    cout << s.longestValidParentheses("()") << endl;
//    cout << s.longestValidParentheses("(()") << endl;
//    cout << s.longestValidParentheses(")()())") << endl;
//    cout << s.longestValidParentheses(")(") << endl;
//    cout << s.longestValidParentheses("") << endl;
    vector<int> vec = {1, 1};
    cout << vec[-1] << endl;
    cout << vec[-2] << endl;
    cout << vec[-3] << endl;
    cout << vec[-100] << endl;
    return 0;
}
