#include <iostream>

// nested way
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    } else if (list2 == nullptr) {
      return list1;
    } else if (list1->val < list2->val) {
      list1->next = mergeToLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
    }
    return list2;
  }
};

// iteration way
class SolutionIteration {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // 创建哨兵节点
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    // 遍历两个链表
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        current->next = list1;
        list1 = list1->next;
      } else {
        current->next = list2;
        list2 = list2->next;
      }
      current = current->next;
    }

    // 连接剩余节点
    current->next = list1 ? list1 : list2;

    // 获取结果并释放哨兵节点
    ListNode *result = dummy->next;
    delete dummy;
    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }
