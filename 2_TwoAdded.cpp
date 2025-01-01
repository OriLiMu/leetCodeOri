// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *result;
        int carry = 0;
        while (p1 != nullptr || p2 != nullptr)
        {
            int sum = 0;
            if (p1 != nullptr && p2 != nullptr)
            {
                sum = p1->val + p2->val;
            }
            else if (p1 == nullptr)
            {
                sum = p2->val;
            }
            else if (p2 == nullptr)
            {
                sum = p1->val;
            }
            else
            {
                // error if run to here
            }

            sum += carry;
            carry = 0;

            int curNum = 0;
            if (sum >= 10)
            {
                carry = 1;
                curNum = sum - 10;
            }
            else
            {
                carry = 0;
                curNum = sum;
            }
        }
    }
};