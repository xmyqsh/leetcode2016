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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for (ListNode* cur = headA; cur; cur = cur->next, ++lenA);
        for (ListNode* cur = headB; cur; cur = cur->next, ++lenB);
        if (lenA > lenB) swap(lenA, lenB), swap(headA, headB);
        for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
        for (; headA && headA != headB; headA = headA->next, headB = headB->next);
        return headA;
    }
};
