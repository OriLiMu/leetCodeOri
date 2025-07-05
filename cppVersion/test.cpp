#include <iostream>
#include <numeric> // 必须包含此头文件
#include <vector>

int main() {
  std::vector<int> empty_vec; // 空向量

  // 示例 1：求和（初始值为 0）
  int sum = std::accumulate(empty_vec.begin(), empty_vec.end(), 0);
  std::cout << "Sum of empty vector: " << sum << std::endl; // 输出: 0

  // 示例 2：求积（初始值为 1）
  int product = std::accumulate(empty_vec.begin(), empty_vec.end(), 1,
                                [](int a, int b) { return a * b; });
  std::cout << "Product of empty vector: " << product << std::endl; // 输出: 1

  // 示例 3：字符串拼接（初始值为 "Hello"）
  std::vector<std::string> empty_words;
  std::string result = std::accumulate(empty_words.begin(), empty_words.end(),
                                       std::string("Hello"));
  std::cout << "Concatenated string: " << result << std::endl; // 输出: Hello

  return 0;
}
