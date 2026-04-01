#include <iostream>
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *result = nullptr;
    ListNode *cur = nullptr;
    int carry = 0;
    while (p1 != nullptr || p2 != nullptr || carry) {
      int sum = 0;
      int val1 = 0;
      int val2 = 0;
      if (p1) {
        val1 = p1->val;
        p1 = p1->next;
      }
      if (p2) {
        val2 = p2->val;
        p2 = p2->next;
      }
      sum = carry + val1 + val2;
      carry = sum / 10;
      if (!cur) {
        cur = new ListNode(sum % 10);
        result = cur;
      } else {
        cur->next = new ListNode(sum % 10);
        cur = cur->next; // Notice: 这里是一个小细节我还是错了
      }
    }

    return result;
  }
};

// 用于打印链表的辅助函数
void printList(ListNode *head) {
  ListNode *current = head;
  while (current != nullptr) {
    std::cout << current->val;
    if (current->next != nullptr) {
      std::cout << " -> ";
    }
    current = current->next;
  }
  std::cout << std::endl;
}

int main() {
  // 创建第一个链表: 2->4->3
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  // 创建第二个链表: 5->6->4
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  // 打印输入的链表
  std::cout << "l1: ";
  printList(l1);
  std::cout << "l2: ";
  printList(l2);

  // 计算结果
  Solution solution;
  ListNode *result = solution.addTwoNumbers(l1, l2);

  // 打印结果
  std::cout << "Result: ";
  printList(result);

  // 清理内存
  while (l1 != nullptr) {
    ListNode *temp = l1;
    l1 = l1->next;
    delete temp;
  }
  while (l2 != nullptr) {
    ListNode *temp = l2;
    l2 = l2->next;
    delete temp;
  }
  while (result != nullptr) {
    ListNode *temp = result;
    result = result->next;
    delete temp;
  }

  return 0;
}
