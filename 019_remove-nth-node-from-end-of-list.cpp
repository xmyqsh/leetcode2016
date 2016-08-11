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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* former = prev;
        for (int i = 0; i < n; ++i)
            former = former->next;
        while (former->next) {
            prev = prev->next;
            former = former->next;
        }
        ListNode* tmp = prev->next;
        prev->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};
