#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;
    ListNode *slow = head, *fast = head;
    do {
      if (slow)
        slow = slow->next;
      if (fast && fast->next)
        fast = fast->next->next;
    } while (slow != fast);
    if (!slow)
      return nullptr;
    ListNode *p = head;
    while (slow != p) {
      slow = slow->next;
      p = p->next;
    }

    return p;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
