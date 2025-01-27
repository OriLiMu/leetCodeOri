#include <cstddef>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseChainList(ListNode *head) {
  if (!head)
    return head;
  ListNode *prev = nullptr;
  ListNode *cur = head;
  ListNode *next = nullptr;
  while (cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  return prev;
}

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode *result = reverseChainList(head);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
