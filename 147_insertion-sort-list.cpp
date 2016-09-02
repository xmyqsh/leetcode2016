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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(INT_MIN);
        for (ListNode* cur = head; cur;) {
            ListNode* next = cur->next;
            ListNode* pos = findInsertPos(&dummy, cur->val);
            cur->next = pos->next;
            pos->next = cur;
            cur = next;
        }
        return dummy.next;
    }
    ListNode* findInsertPos(ListNode* head, int val) {
        ListNode* prev = NULL;
        for (ListNode* cur = head; cur && cur->val <= val; prev = cur, cur = cur->next);
        return prev;
    }
};
