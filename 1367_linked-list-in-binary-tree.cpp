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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root->left && isSubPath(head, root->left)) return true;     // try skip first
        if (root->right && isSubPath(head, root->right)) return true;   // try skip first
        return isSubPath2(head, root);                                  // back trace
    }
    bool isSubPath2(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (head->val != root->val) return false;                       // break immediately
        return isSubPath2(head->next, root->left) ||
               isSubPath2(head->next, root->right);
    }
};
