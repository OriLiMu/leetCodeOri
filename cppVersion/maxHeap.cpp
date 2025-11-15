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
  int c1 = fatherIdx * 2, c2 = fatherIdx * 2 + 1;
  while (true) {
    if (c1 < mh_size && mh[fatherIdx] < mh[c1]) {
      swap(mh[fatherIdx], mh[c1]);
      fatherIdx = c1;
      c1 = fatherIdx * 2, c2 = fatherIdx * 2 + 1;
    } else if (c2 < mh_size && mh[fatherIdx] < mh[c2]) {
      swap(mh[fatherIdx], mh[c2]);
      fatherIdx = c2;
      c1 = fatherIdx * 2, c2 = fatherIdx * 2 + 1;
    }

    if (fatherIdx > mh_size)
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
  mh[mh_size] = n;
  siftUp();
}

int main() {
  cout << "hi" << endl;
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  for (auto &n : v) {
    insert(n);
  }

  displayTree();
}
