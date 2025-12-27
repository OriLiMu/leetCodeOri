#include <algorithm>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <random>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class MinStack {
public:
  vector<int> realStk;
  vector<int> minStk;
  int curMin;
  MinStack() {}

  void push(int val) {
    if (realStk.empty() || val < curMin) {
      curMin = val;
    }
    realStk.push_back(val);
    minStk.push_back(curMin);
  }

  void pop() {
    realStk.pop_back();
    minStk.pop_back();
    // 这里还是有一个语法的错误
    if (!minStk.empty())
      curMin = minStk.back();
  }

  int top() { return realStk.back(); }

  int getMin() { return minStk.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
  Solution s;
  cout << "hello" << endl;
}
