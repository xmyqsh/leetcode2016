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
    int maxSumBST(TreeNode* root) {
        auto [ret, s, valid] = dfs(root);
        return ret;
    }
    tuple<int, int, bool> dfs(TreeNode* root) {
        if (!root) return tuple(0, 0, true);
        auto [lRet, ls, lValid] = dfs(root->left);
        auto [rRet, rs, rValid] = dfs(root->right);
        auto valid = lValid && rValid && (!root->left || root->left->val < root->val)
                                      && (!root->right || root->right->val > root->val);
        auto s = ls + rs + root->val;
        auto ret = max(lRet, rRet);
        if (valid) ret = max(ret, s);
        return tuple(ret, s, valid);
    }
};
