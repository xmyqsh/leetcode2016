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
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        stack<TreeNode*> sk;
        while (!sk.empty() || root) {
            if (root) {
                sk.push(root);
                root = root->left;
            } else {
                root = sk.top();
                sk.pop();
                if (prev && prev->val > root->val) {
                    if (!first) first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            }
        }
        swap(first->val, second->val);
    }
};
