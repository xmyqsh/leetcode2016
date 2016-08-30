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
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        } else {
            ListNode* newHead = head->next;
            while (newHead && newHead->val == head->val) {
                ListNode* tmp = newHead;
                newHead = newHead->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicates(newHead);
        }
    }
};
