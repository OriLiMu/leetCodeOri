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
    ListNode *p1 = head;
    ListNode *p2 = head;
    for (int i = 0; i < n; i++)
      p1 = p1->next;
    ListNode *lastP2 = p2;
    while (p1) {
      p1 = p1->next;
      lastP2 = p2;
      p2 = p2->next;
    }

    if (lastP2 != p2) {
      lastP2->next = p2->next;
    } else {
      head = head->next;
    }

    return head;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
