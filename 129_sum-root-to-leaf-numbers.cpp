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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode* root, int sum) {
        if (!root) return 0;
        if (!root->left && !root->right) return 10 * sum + root->val;
        return sumNumbers(root->left, 10 * sum + root->val) +
                sumNumbers(root->right, 10 * sum + root->val);
    }
};
