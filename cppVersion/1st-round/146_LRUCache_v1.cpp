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
  struct Node {
    int key;
    int val;
    Node *left;
    Node *right;
    Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr) {}
  };

  // 这个函数是给k,v还是指针, 这里假定p里面的值已经填好了
  void prepend(Node *p) {
    Node *tmp = L->right;
    L->right = p;
    p->left = L, p->right = tmp, tmp->left = p;
  }
  void remove(Node *p) {
    Node *l = p->left, *r = p->right;
    l->right = r, r->left = l;
    // delete p; 这里不做处理
  }

  int CAP, cnt = 0; // 这里的这个cnt用hash.size() 替代更好
  unordered_map<int, Node *> hash;
  Node *L = new Node(-1, -1), *R = new Node(-1, -1);

  LRUCache(int capacity) {
    CAP = capacity;
    L->right = R, R->left = L;
  }

  int get(int key) {
    if (!hash.count(key))
      return -1;
    remove(hash[key]);
    // 这里有一个逻辑需要注意. 这一步就是更新node的位置到队首
    // 那么在这种逻辑之下, remove的处理就很有意思,
    // 这一步应该只是把node从队列中剔除, 而至于node本身这个节点是不是删除
    // 不考虑, 因为有可能会被外面使用
    // 思考了一下, 这个node应该被无限次使用,
    // 当第一次创建了等于capacity的数量的node之后, 这些node就被无限次使用了
    prepend(hash[key]);
    return hash[key]->val;
  }

  // 他这里的关键操作就是不管怎么样直接删除
  void put(int key, int value) {
    if (hash.count(key))
      remove(hash[key]);
    else if (cnt == CAP) {
      // 这里的先后的顺序搞错了, 这里需要两个操作, 断开最后一个节点,
      // 把最后一个节点对应的key在hash里面删掉
      hash[key] = R->left;
      remove(R->left);
      hash.erase(hash[key]->key);
      // 这个时候还需要处理hash里面的内容, 这个时候需要key
    } else {
      hash[key] = new Node(-1, -1); // 这里一开始没注意
      cnt++;                        // 这道题的逻辑没有 cnt--的地方
    }

    hash[key]->key = key;
    hash[key]->val = value;
    prepend(hash[key]);
  }
};

/* 测试用例 */
int main() {
  LRUCache lru(2); // 容量为 2

  lru.put(1, 10);
  lru.put(2, 20);
  cout << lru.get(1) << endl; // 返回 10，此时顺序: 2 -> 1
  lru.put(3, 30);             // 淘汰 key=2
  cout << lru.get(2) << endl; // 返回 -1 (未找到)
  lru.put(4, 40);             // 淘汰 key=1
  cout << lru.get(1) << endl; // 返回 -1 (未找到)
  cout << lru.get(3) << endl; // 返回 30
  cout << lru.get(4) << endl; // 返回 40
  return 0;
}
