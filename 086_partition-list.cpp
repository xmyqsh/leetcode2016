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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode dummyS(-1), dummyB(-1);
        ListNode *prevS = &dummyS, *prevB = &dummyB;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val < x) prevS->next = cur, prevS = prevS->next;
            else prevB->next = cur, prevB = prevB->next;
        }
        prevS->next = dummyB.next, prevB->next = NULL;
        return dummyS.next;
    }
};
