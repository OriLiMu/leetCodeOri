#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string str = "abcd";

  // 使用反向迭代器构造反转字符串
  reverse(str.begin(), str.begin() + 2);
  std::cout << "Reversed string: " << str << std::endl; // 输出 "bacd"
  return 0;
}
