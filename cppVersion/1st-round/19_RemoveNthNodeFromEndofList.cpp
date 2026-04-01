#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // 注意你这个思路的前提的条件是, p1 p2 最后不能挨着.
    // 这个是非常隐性的一个判断的条件
    ListNode *p1 = nullptr;
    ListNode *p2 = nullptr;
    for (int i = 0; i < n; i++) {
      if (!p1)
        p1 = head;
      else
        p1 = p1->next;
    }
    while (p1->next) {
      p1 = p1->next;
      if (!p2)
        p2 = head;
      else
        p2 = p2->next;
    }

    if (!p2) {
      head = head->next;
    } else {
      p2->next = p1;
    }

    return head;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
