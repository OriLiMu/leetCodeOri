# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = l1
        n2 = l2
        carry = 0
        dummy = ListNode()
        current = dummy
        while n1 or n2 or carry:
            addend1 = n1.val if n1 else 0
            addend2 = n2.val if n2 else 0
            sum = carry + addend1 + addend2
            carry = sum // 10
            digit = sum % 10
            n1 = n1.next if n1 else None
            n2 = n2.next if n2 else None
            current.next = ListNode(digit)
            current = current.next

        return dummy.next

