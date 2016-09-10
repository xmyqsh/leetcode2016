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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        for (this->head = head, len = 0; head; ++len, head = head->next);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand() % len;
        ListNode* head = this->head;
        while (idx--) head = head->next;
        return head->val;
    }
private:
    int len;
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
