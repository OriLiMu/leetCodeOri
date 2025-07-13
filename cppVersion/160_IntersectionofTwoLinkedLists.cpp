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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int cnt1 = 0, cnt2 = 0;
    ListNode *n1 = headA;
    ListNode *n2 = headB;
    while (n1) {
      n1 = n1->next;
      cnt1++;
    }
    while (n2) {
      n2 = n2->next;
      cnt2++;
    }

    n1 = headA;
    n2 = headB;
    if (cnt2 > cnt1) {
      for (int i = 0; i < cnt2 - cnt1; i++) {
        n2 = n2->next;
      }
    } else if (cnt1 > cnt2) {
      for (int i = 0; i < cnt1 - cnt2; i++) {
        n1 = n1->next;
      }
    }

    while (n1 && n2 && n1 != n2) {
      n1 = n1->next;
      n2 = n2->next;
    }
    if (n1)
      return n1;
    return nullptr;
  }
};
int main() { Solution s; }
