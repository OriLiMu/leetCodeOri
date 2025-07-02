#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // 获取最后一个元素
  int last_element = vec.back();

  std::cout << "Last element: " << last_element << std::endl; // 输出 5
  return 0;
}
