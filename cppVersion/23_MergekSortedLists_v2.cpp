#include <algorithm>
#include <bits/ostream.h>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  struct cmp {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    for (auto p : lists) {
      if (p)
        pq.push(p);
    }

    ListNode dummy;
    ListNode *tail = &dummy;
    while (pq.size()) {
      auto t = pq.top();
      tail = tail->next = t;
      pq.pop();
      if (t->next)
        pq.push(t->next);
    }

    return dummy.next;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
