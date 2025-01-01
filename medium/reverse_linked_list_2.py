# Time complexity: O(n)
# Space complexity: O(1)

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(None, head)
        
        start, cur = dummy, head
        for _ in range(left - 1):
            start = start.next
            cur = cur.next
        
        prev = None
        for _ in range(right - left + 1):
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp

        start.next.next = cur
        start.next = prev

        return dummy.next
