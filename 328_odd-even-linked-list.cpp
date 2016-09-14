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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummyOdd(-1), dummyEven(-1);
        ListNode *odd = &dummyOdd, *even = &dummyEven;
        while (head) {
            odd->next = head;
            odd = odd->next;
            if (!(head = head->next)) break;
            even->next = head;
            even = even->next;
            head = head->next;
        }
        odd->next = dummyEven.next;
        even->next = NULL;
        return dummyOdd.next;
    }
};
