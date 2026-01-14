#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class MedianFinder {
public:
  int qsize;
  priority_queue<int, vector<int>> maxhp;
  priority_queue<int, vector<int>, greater<int>> minhp;
  MedianFinder() { qsize = 0; }

  void addNum(int num) {
    qsize++;
    if (maxhp.empty()) {
      maxhp.push(num);
      return;
    }

    if (qsize % 2 == 0) {
      if (num >= maxhp.top())
        minhp.push(num);
      else { // 从一堆数字里面拿出来一个数字再插入到另一个堆里
        int t = maxhp.top();
        maxhp.pop();
        maxhp.push(num);
        minhp.push(t);
      }
    } else {
      if (num <= minhp.top())
        maxhp.push(num);
      else {
        int t = minhp.top();
        minhp.pop();
        minhp.push(num);
        maxhp.push(t);
      }
    }
  }

  double findMedian() {
    if (qsize % 2)
      return maxhp.top();
    else
      return (maxhp.top() + minhp.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main() {
  // 测试用例1: 基本功能测试
  cout << "测试用例1: 基本功能测试" << endl;
  MedianFinder mf1;
  mf1.addNum(1);
  cout << "addNum(1), median = " << mf1.findMedian() << endl; // 期望: 1

  mf1.addNum(2);
  cout << "addNum(2), median = " << mf1.findMedian() << endl; // 期望: 1.5

  mf1.addNum(3);
  cout << "addNum(3), median = " << mf1.findMedian() << endl; // 期望: 2

  cout << endl;

  // 测试用例2: 逆序插入
  cout << "测试用例2: 逆序插入" << endl;
  MedianFinder mf2;
  mf2.addNum(3);
  cout << "addNum(3), median = " << mf2.findMedian() << endl; // 期望: 3

  mf2.addNum(2);
  cout << "addNum(2), median = " << mf2.findMedian() << endl; // 期望: 2.5

  mf2.addNum(1);
  cout << "addNum(1), median = " << mf2.findMedian() << endl; // 期望: 2

  cout << endl;

  // 测试用例3: 负数
  cout << "测试用例3: 负数" << endl;
  MedianFinder mf3;
  mf3.addNum(-1);
  cout << "addNum(-1), median = " << mf3.findMedian() << endl; // 期望: -1

  mf3.addNum(-2);
  cout << "addNum(-2), median = " << mf3.findMedian() << endl; // 期望: -1.5

  mf3.addNum(-3);
  cout << "addNum(-3), median = " << mf3.findMedian() << endl; // 期望: -2

  cout << endl;

  // 测试用例4: 随机插入
  cout << "测试用例4: 随机插入" << endl;
  MedianFinder mf4;
  mf4.addNum(5);
  cout << "addNum(5), median = " << mf4.findMedian() << endl; // 期望: 5

  mf4.addNum(2);
  cout << "addNum(2), median = " << mf4.findMedian() << endl; // 期望: 3.5

  mf4.addNum(3);
  cout << "addNum(3), median = " << mf4.findMedian() << endl; // 期望: 3

  mf4.addNum(1);
  cout << "addNum(1), median = " << mf4.findMedian() << endl; // 期望: 2.5

  mf4.addNum(4);
  cout << "addNum(4), median = " << mf4.findMedian() << endl; // 期望: 3

  cout << endl;

  // 测试用例5: 大量数据
  cout << "测试用例5: 大量数据" << endl;
  MedianFinder mf5;
  for (int i = 1; i <= 10; i++) {
    mf5.addNum(i);
    cout << "addNum(" << i << "), median = " << mf5.findMedian() << endl;
  }

  cout << endl;
  cout << "所有测试用例完成！" << endl;

  return 0;
}
