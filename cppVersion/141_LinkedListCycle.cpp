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
  bool hasCycle(ListNode *head) {
    ListNode *p1 = head;
    ListNode *p2 = head;
    do {
      if (p1 != nullptr || p1->next != nullptr)
        return false;
      else
        p1 = p1->next->next;
      p2 = p2->next;
    } while (p1 != p2);
    if (!p1) // 这个可以去掉
      return false;
    return true;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
