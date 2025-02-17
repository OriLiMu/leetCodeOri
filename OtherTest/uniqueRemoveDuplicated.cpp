#include <algorithm> // 包含 std::unique
#include <iostream>
#include <vector>

int main() {
  // 初始化向量
  std::vector<int> vec = {1, 2, 3, 4, 5, 1};

  // 对 vect 进行排序（虽对于 std::unique 不是必需的，但通常来讲最好先排序）
  std::sort(vec.begin(), vec.end());

  // 使用 std::unique 移除重复元素
  auto last = std::unique(vec.begin(), vec.end());

  // 删除重复后面的元素
  vec.erase(last, vec.end());

  // 输出结果
  for (int num : vec) {
    std::cout << num << " ";
  }

  return 0;
}
