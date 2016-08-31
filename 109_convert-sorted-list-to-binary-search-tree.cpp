/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (ListNode* cur = head; cur; ++len, cur = cur->next);
        return convert(head, len);
    }
    TreeNode* convert(ListNode* head, int len) {
        if (len <= 0) return NULL;
        ListNode* mid = head;
        for (int i = 0; i < len / 2; ++i, mid = mid->next);
        TreeNode* root = new TreeNode(mid->val);
        root->left = convert(head, len / 2);
        root->right = convert(mid->next, len - len / 2 - 1);
        return root;
    }
};
