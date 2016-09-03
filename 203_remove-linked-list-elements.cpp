/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (; prev->next;) {
            if (prev->next->val == val) {
                ListNode* tmp = prev->next;
                prev->next = tmp->next;
                delete tmp;
            } else prev = prev->next;
        }
        return dummy.next;
    }
};
