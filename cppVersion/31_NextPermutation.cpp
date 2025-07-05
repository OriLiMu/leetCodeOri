#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {1, 3, 5, 7};

  // 查找存在的值3
  cout << "=== 查找存在的值3 ===" << endl;
  auto lb3 = lower_bound(vec.begin(), vec.end(), 3);
  cout << "lower_bound 位置：" << (lb3 - vec.begin()) << "，元素值：" << *lb3
       << endl;

  auto ub3 = upper_bound(vec.begin(), vec.end(), 3);
  cout << "upper_bound 位置：" << (ub3 - vec.begin()) << "，元素值：" << *ub3
       << "\n\n";

  // 查找不存在的值4
  cout << "=== 查找不存在的值4 ===" << endl;
  auto lb4 = lower_bound(vec.begin(), vec.end(), 4);
  cout << "lower_bound 位置：" << (lb4 - vec.begin()) << "，元素值：" << *lb4
       << endl;

  auto ub4 = upper_bound(vec.begin(), vec.end(), 4);
  cout << "upper_bound 位置：" << (ub4 - vec.begin()) << "，元素值：" << *ub4
       << "\n\n";

  // 查找大于所有元素的值8
  cout << "=== 查找值8 ===" << endl;
  auto lb8 = lower_bound(vec.begin(), vec.end(), 8);
  if (lb8 == vec.end()) {
    cout << "lower_bound 返回 end 迭代器" << endl;
  }

  auto ub8 = upper_bound(vec.begin(), vec.end(), 8);
  if (ub8 == vec.end()) {
    cout << "upper_bound 返回 end 迭代器" << endl;
  }

  return 0;
}
