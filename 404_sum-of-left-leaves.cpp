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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return sumOfLeftLeaves(root, false);
    }
    int sumOfLeftLeaves(TreeNode* root, bool isLeft) {
        if (!root->left && !root->right && isLeft) return root->val;
        return (root->left ? sumOfLeftLeaves(root->left, true) : 0) +
                (root->right ? sumOfLeftLeaves(root->right, false) : 0);
    }
};
