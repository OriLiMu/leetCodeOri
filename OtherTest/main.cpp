#include <algorithm> // for std::sort
#include <iostream>
#include <string>
#include <vector>

int main() {
  // 示例：一个包含字符串的 vector
  std::vector<std::string> vec = {"hello", "world", "cpp", "algorithm"};

  // 对每个字符串中的字符进行排序
  for (auto &str : vec) {
    std::sort(str.begin(), str.end());
  }

  // 输出排序后的结果
  for (const auto &str : vec) {
    std::cout << str << std::endl;
  }

  return 0;
}

