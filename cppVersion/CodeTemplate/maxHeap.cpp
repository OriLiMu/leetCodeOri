#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
vector<int> mh(100);
int mh_size = 0;

void siftUp() {
  int curIdx = mh_size - 1; // 这里可能是-1
  int fatherIdx = (curIdx - 1) / 2;
  while (curIdx > 0 && mh[curIdx] > mh[fatherIdx]) {
    swap(mh[curIdx], mh[fatherIdx]);
    curIdx = fatherIdx;
    fatherIdx = (curIdx - 1) / 2;
  }
}

void siftDown() {
  int fatherIdx = 0;
  int c1 = fatherIdx * 2 + 1, c2 = fatherIdx * 2 + 2;
  while (true) {
    // 这里不是谁比father大就能上, 还要比兄弟大
    // 这里可能 c1是在范围之内，但是c2在范围之外
    if (c1 < mh_size && mh[fatherIdx] < mh[c1] && mh[c1] > mh[c2]) {
      swap(mh[fatherIdx], mh[c1]);
      fatherIdx = c1;
      c1 = fatherIdx * 2 + 1, c2 = fatherIdx * 2 + 2;
    } else if (c2 < mh_size && mh[fatherIdx] < mh[c2] && mh[c1] < mh[c2]) {
      swap(mh[fatherIdx], mh[c2]);
      fatherIdx = c2;
      c1 = fatherIdx * 2 + 1, c2 = fatherIdx * 2 + 2;
    }

    // 注意
    // 如果这里的 c1, c2超出范围, 那么上面两个流程都不会走
    // fatherIdx永远在范围之后, c1, c2在范围之内陷入死循环
    // 核心问题就是, 如果你需要fatherIdx作为判断跳出条件
    // 那么, 需要注意严格更新 fatherIdx的值, 不能被其他因素影响
    if (c1 >= mh_size)
      break;
  }
}

void displayTree() {
  int newlineCount = 1;
  int curCout = 0;
  for (int i = 0; i < mh_size; ++i) {
    curCout++;
    cout << mh[i] << ", ";
    if (curCout == newlineCount) {
      curCout = 0;
      newlineCount *= 2;
      cout << endl;
    }
  }
}

void insert(int n) {
  mh_size++;
  mh[mh_size - 1] = n;
  siftUp();
}

void popTop() {
  mh[0] = mh[mh_size - 1];
  mh_size--;
  siftDown();
}

int main() {
  cout << "hi" << endl;
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  for (auto &n : v) {
    insert(n);
  }

  displayTree();
}
