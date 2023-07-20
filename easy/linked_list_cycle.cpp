/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Slow pointer, fast pointer
 // beautiful solution

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL) {
            if (fast == slow) {
                return true;
            }
            if (fast->next == nullptr) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};