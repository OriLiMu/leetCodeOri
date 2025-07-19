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
  bool isPalindrome(ListNode *head) {
    vector<int> save;
    ListNode *cur = head;
    ListNode *last = nullptr;
    ListNode *next = cur->next;
    while (cur) {
      save.push_back(cur->val);
      next = cur->next;
      cur->next = last;
      last = cur;
      cur = next;
    }

    cur = last;
    for (auto n : save) {
      if (n != cur->val)
        return false;
      cur = cur->next;
    }
    return true;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
