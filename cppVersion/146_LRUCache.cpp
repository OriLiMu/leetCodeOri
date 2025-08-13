#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
class LRUCache {
public:
  int CAP, avbCount;
  unordered_map<int, int> data;
  priority_queue<int, vector<int>, greater<int>>

  LRUCache(int capacity) {
    CAP = capacity;
    avbCount = CAP;
  }

  int get(int key) {}

  void put(int key, int value) {}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
  Solution s;
  cout << "hello" << endl;
}
