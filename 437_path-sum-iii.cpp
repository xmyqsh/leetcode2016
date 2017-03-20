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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return curPathSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int curPathSum(TreeNode* root, int preSum, int sum) {
        if (!root) return 0;
        return (preSum + root->val == sum) + curPathSum(root->left, preSum + root->val, sum) + curPathSum(root->right, preSum + root->val, sum);
    }
};
