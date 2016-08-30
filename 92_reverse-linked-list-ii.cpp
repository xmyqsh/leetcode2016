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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 1; i < m; ++i) prev = prev->next;
        ListNode* tail = prev->next;
        for (int i = m; i < n; ++i) {
            ListNode* cur = tail->next;
            tail->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }
        return dummy.next;
    }
};
