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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* anotherHead = reverse(slow->next);
        slow->next = NULL;
        for (ListNode* cur = head; cur && anotherHead; cur = cur->next->next) {
            ListNode* next = anotherHead->next;
            anotherHead->next = cur->next;
            cur->next = anotherHead;
            anotherHead = next;
        }
    }
    ListNode* reverse(ListNode* head) {
        if (!head) return NULL;
        ListNode* prev = NULL;
        for (ListNode* cur = head; cur;) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
