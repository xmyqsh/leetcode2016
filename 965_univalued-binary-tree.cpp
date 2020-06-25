/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        auto [v, b] = isUnivalTree1(root);
        return b;
    }
    tuple <int, bool> isUnivalTree1(TreeNode* root) {
        if (!root) return {-1, true};
        auto [vL, bL] =  isUnivalTree1(root->left);
        auto [vR, bR] =  isUnivalTree1(root->right);
        if (!bL || !bR) return {-1, false};
        if (vL != -1 && vL != root->val) return {-1, false};
        if (vR != -1 && vR != root->val) return {-1, false};
        return {root->val, true};
    }
};
