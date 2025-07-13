#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> v = {1, 2, 3};
  int x = v[3]; // ❌ 越界，v.size() == 3，最大合法索引是 2
  return 0;
}
