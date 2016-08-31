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
    int minDepth(TreeNode* root) {
        return minDepth(root, NULL);
    }
    int minDepth(TreeNode* root, TreeNode* brother) {
        if (!root) return brother ? INT_MAX : 0;
        return 1 + min(minDepth(root->left, root->right), minDepth(root->right, root->left));
    }
};
