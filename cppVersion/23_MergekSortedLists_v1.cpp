#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <istream>
#include <queue>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildChainTable(const std::vector<int> &nums) {
  if (nums.empty())
    return nullptr;

  ListNode *head = new ListNode(nums[0]);
  ListNode *cur = head;

  for (size_t i = 1; i < nums.size(); ++i) {
    cur->next = new ListNode(nums[i]);
    cur = cur->next;
  }
  return head;
}

class Solution {
public:
  struct Node {
    ListNode *ln;
    int index;
    Node(ListNode *ln, int idx) : ln(ln), index(idx) {}
  };
  struct Comparator {
    bool operator()(Node &a, Node &b) { return a.ln->val > b.ln->val; }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<Node, vector<Node>, Comparator> pq;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i]) {
        pq.push(Node(lists[i], i));
        lists[i] = lists[i]->next;
      }
    }

    // ListNode dummy, *cur = dummy.next; // 这里是一个经典的错误, cur =
    // dummy.next 并没有把两者联系在一起
    // 如果你需要修改一个节点的next指针, 你的cur就需要等于当前的这个节点
    ListNode dummy;
    ListNode *cur = &dummy;
    while (!pq.empty()) {
      Node t = pq.top();
      cur->next = t.ln;
      cur = cur->next;
      pq.pop();
      if (lists[t.index]) {
        pq.push(Node(lists[t.index], t.index));
        lists[t.index] = lists[t.index]->next;
      }
    }

    return dummy.next;
  }
};
int main() {
  Solution s;
  vector<ListNode *> v;
  vector<vector<int>> vv = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
  for (auto t : vv) {
    v.push_back(buildChainTable(t));
  }
  ListNode *r = s.mergeKLists(v);

  cout << "hello" << endl;
}
