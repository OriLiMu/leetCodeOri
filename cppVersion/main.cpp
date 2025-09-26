#include <deque>
#include <iostream>
#include <set>

int main() {
  // 原始 deque
  std::deque<int> dq = {10, 20, 30};

  // 从尾部插入（push_back）
  dq.push_back(40); // dq: [10, 20, 30, 40]

  // 从头部插入（push_front）
  dq.push_front(5); // dq: [5, 10, 20, 30, 40]

  // 插入 set 的所有元素到 deque 尾部
  std::set<int> s = {100, 200};
  dq.insert(dq.end(), s.begin(), s.end()); // dq: [5, 10, 20, 30, 40, 100, 200]

  // 在指定位置插入单个元素（比如第 3 个位置）
  dq.insert(dq.begin() + 2, 999); // dq: [5, 10, 999, 20, 30, 40, 100, 200]

  // 遍历输出
  for (int x : dq)
    std::cout << x << " ";
  return 0;
}
