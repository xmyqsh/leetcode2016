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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* newHead = head;
        int i = 0;
        for (; i < k && newHead; ++i) {
            newHead = newHead->next;
        }
        if (i < k) return head;
        ListNode* prev = reverseKGroup(newHead, k);
        for (ListNode* cur = head; cur != newHead;) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
