#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

// 阻止编译器把循环优化掉
inline void clobber() { asm volatile("" ::: "memory"); }

template <typename F> uint64_t measure(const vector<int> &v, F f) {
  auto t0 = high_resolution_clock::now();
  for (uint64_t i = 0; i < 200'000'000ULL; ++i) {
    bool sink = f(v); // 真正执行 empty 或 size==0
    clobber();        // 强制结果不可丢弃
  }
  auto t1 = high_resolution_clock::now();
  return duration_cast<nanoseconds>(t1 - t0).count();
}

int main() {
  vector<int> v(10); // 非空，防止常量折叠
  auto t_empty = measure(v, [](const auto &c) { return c.empty(); });
  auto t_size = measure(v, [](const auto &c) { return c.size() == 0; });

  cout << "empty : " << t_empty << " ns\n";
  cout << "size  : " << t_size << " ns\n";
  cout << "ratio : " << (double)t_empty / t_size << "\n";
}
