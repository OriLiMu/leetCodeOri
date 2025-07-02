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
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;
    ListNode *third = head->next->next;
    ListNode *second = head->next;
    second->next = head;
    head->next = swapPairs(third);
    return second;
  }
};

int main() {
  // give me 5 examples
  // 2 1 4 3 5 6 7 8 9 10
  Solution s;
  ListNode *head = new ListNode(
      2,
      new ListNode(
          1, new ListNode(
                 4, new ListNode(
                        3, new ListNode(
                               5, new ListNode(
                                      6, new ListNode(
                                             7, new ListNode(
                                                    8, new ListNode(
                                                           9, new ListNode(
                                                                  10))))))))));
  ListNode *result = s.swapPairs(head);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;
}
