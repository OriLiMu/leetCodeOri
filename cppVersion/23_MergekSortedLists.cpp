#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

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
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
    }
    return list2;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;
    if (lists.size() == 1)
      return lists[0];
    ListNode *result = mergeTwoLists(lists[0], lists[1]);
    int count = 2;
    while (count < lists.size()) {
      result = mergeTwoLists(result, lists[count]);
      count++;
    }

    return result;
  }
};

int main() {
  Solution s;
  cout << "hello" << endl;
}
