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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        int carry = 0;
        for (; l1 || l2; l1 = l1 ? l1->next : l1, l2 = l2 ? l2->next : l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
        }
        if (carry)
            cur->next = new ListNode(1);
        return dummy.next;
    }
};
