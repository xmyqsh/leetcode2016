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
    int rob(TreeNode* root) {
        int l, r;
        return rob(root, l, r);
    }
    int rob(TreeNode* root, int& l, int& r) {
        if (!root) return l = r = 0;
        int ll, lr, rl, rr;
        l = rob(root->left, ll, lr);
        r = rob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};
