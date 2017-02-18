// I don't reverse the input list

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
        int n1 = 0, n2 = 0, carry;
        for (ListNode* cur = l1; cur; cur = cur->next, ++n1);
        for (ListNode* cur = l2; cur; cur = cur->next, ++n2);
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        if (n1 < n2) carry = addTwoNumbers(cur, l2, l1, n2, n1);
        else carry = addTwoNumbers(cur, l1, l2, n1, n2);
        if (carry) cur->next = new ListNode(1);
        return reverseList(dummy.next);
    }
    int addTwoNumbers(ListNode*& cur, ListNode* l1, ListNode* l2, int n1, int n2) {
        if (n1 == 0) return 0;
        int sum;
        if (n1 == n2) sum = l1->val + l2->val + addTwoNumbers(cur, l1->next, l2->next, n1 - 1, n2 - 1);
        else sum = l1->val + addTwoNumbers(cur, l1->next, l2, n1 - 1, n2);
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        return sum / 10;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = NULL;
        for (ListNode* cur = head; cur; ) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
