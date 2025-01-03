# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        even = head
        firstOdd = head.next
        odd = head.next

        while odd and odd.next:
            even.next = odd.next
            even = even.next

            odd.next = even.next
            odd = odd.next

        # Reattach firstOdd to end of evens
        even.next = firstOdd

        return head