/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode* cur = head; cur; cur = cur->next->next) {
            RandomListNode* next = new RandomListNode(cur->label);
            next->next = cur->next;
            cur->next = next;
        }
        for (RandomListNode* cur = head; cur; cur = cur->next->next) {
            if (cur->random)
                cur->next->random = cur->random->next;
        }
        RandomListNode dummy(-1);
        for (RandomListNode *cur = head, *prev = &dummy; cur;) {
            prev->next = cur->next;
            prev = prev->next;
            cur->next = prev->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
