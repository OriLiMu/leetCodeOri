#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class MinHeap {
public:
  MinHeap() = default;

  /* 构造堆：O(n) 建堆算法 */
  explicit MinHeap(const std::vector<T> &data) : heap_(data) { buildHeap(); }

  /* 元素个数 */
  size_t size() const { return heap_.size(); }

  /* 是否为空 */
  bool empty() const { return heap_.empty(); }

  /* 查看最小值（堆顶） */
  const T &top() const {
    if (empty())
      throw std::runtime_error("Heap is empty");
    return heap_.front();
  }

  /* 插入元素：上浮 */
  void push(const T &value) {
    heap_.push_back(value);
    siftUp(heap_.size() - 1);
  }

  /* 删除最小值：下沉 */
  void pop() {
    if (empty())
      throw std::runtime_error("Heap is empty");
    std::swap(heap_.front(), heap_.back());
    heap_.pop_back();
    if (!empty())
      siftDown(0);
  }

  /* 打印堆（调试用） */
  void print() const {
    for (const auto &v : heap_)
      std::cout << v << ' ';
    std::cout << '\n';
  }

private:
  std::vector<T> heap_;

  /* 建堆：自底向上下沉 */
  void buildHeap() {
    for (int i = static_cast<int>(heap_.size() / 2) - 1; i >= 0; --i)
      siftDown(i);
  }

  /* 上浮：当前节点小于父节点时交换 */
  void siftUp(size_t idx) {
    while (idx > 0) {
      size_t parent = (idx - 1) / 2;
      if (heap_[idx] < heap_[parent]) {
        std::swap(heap_[idx], heap_[parent]);
        idx = parent;
      } else {
        break;
      }
    }
  }

  /* 下沉：当前节点大于子节点时交换 */
  void siftDown(size_t idx) {
    size_t n = heap_.size();
    while (true) {
      size_t left = 2 * idx + 1;
      size_t right = 2 * idx + 2;
      size_t smallest = idx;

      if (left < n && heap_[left] < heap_[smallest])
        smallest = left;
      if (right < n && heap_[right] < heap_[smallest])
        smallest = right;
      if (smallest == idx)
        break;

      std::swap(heap_[idx], heap_[smallest]);
      idx = smallest;
    }
  }
};

/* 演示 */
int main() {
  MinHeap<int> h;
  h.push(9);
  h.push(4);
  h.push(7);
  h.push(1);
  h.push(3);
  h.print(); // 可能输出：1 3 7 9 4

  std::cout << "min = " << h.top() << '\n'; // 1
  h.pop();
  h.print(); // 可能输出：3 4 7 9

  /* 用已有数组建堆 */
  std::vector<int> v{5, 2, 8, 4, 1, 9};
  MinHeap<int> h2(v);
  h2.print(); // 可能输出：1 2 8 4 5 9
  return 0;
}
