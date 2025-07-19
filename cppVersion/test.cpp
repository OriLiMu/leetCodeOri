#include <deque>
#include <iostream>
using namespace std;

int main() {
  // 1) 错误示范：用迭代器遍历并 pop_front —— UB！
  {
    deque<int> dq{1, 2, 3, 4};
    cout << "=== Wrong way (UB) ===\n";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      cout << *it << ' ';
      dq.pop_front(); // 删除首元素，迭代器失效
    }
    cout << "\nAfter loop, dq.size() = " << dq.size() << "\n\n";
  }

  // 2) 正确写法：用 while 循环
  {
    deque<int> dq{1, 2, 3, 4};
    cout << "=== Correct way ===\n";
    while (!dq.empty()) {
      int val = dq.front();
      cout << val << ' ';
      dq.pop_front(); // 安全：不依赖迭代器
    }
    cout << "\nafter loop, dq.size() = " << dq.size() << '\n';
  }
  return 0;
}
