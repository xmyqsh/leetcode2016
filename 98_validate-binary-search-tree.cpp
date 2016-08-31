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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValidBST(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
    
    bool isValidBST(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        return root->val > lower &&
                root->val < upper &&
                isValidBST(root->left, lower, root->val) &&
                isValidBST(root->right, root->val, upper);
    }
};
