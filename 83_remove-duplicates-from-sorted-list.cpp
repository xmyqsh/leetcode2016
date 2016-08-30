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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        while (newHead && newHead->val == head->val) {
            ListNode* tmp = newHead;
            newHead = newHead->next;
            delete tmp;
        }
        head->next = deleteDuplicates(newHead);
        return head;
    }
};
