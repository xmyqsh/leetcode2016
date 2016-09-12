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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *prev = head;
        int n = 1;
        while (prev->next) prev = prev->next, ++n;
        prev->next = head;
        ListNode *cur = head;
        for (int i = 0; i < n - (k % n); ++i, prev = prev->next, cur = cur->next);
        prev->next = NULL;
        return cur;
    }
};
