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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int result = root->val;
        travel(root, result);
        return result;
    }
    int travel(TreeNode* root, int& result) {
        if (!root) return 0;
        int left = travel(root->left, result);
        int right = travel(root->right, result);
        int ret = max(0, max(left, right)) + root->val;
        result = max(max(result, ret), left + right + root->val);
        return ret;
    }
};
