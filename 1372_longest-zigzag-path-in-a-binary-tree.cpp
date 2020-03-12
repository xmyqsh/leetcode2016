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
    int longestZigZag(TreeNode* root) {
        auto [b, l, r] = dfs(root);
        return b - 1;
    }
    tuple<int, int, int> dfs(TreeNode* root) {
        if (!root) return tuple(0, 0, 0);
        auto [lb, ll, lr] = dfs(root->left);
        auto [rb, rl, rr] = dfs(root->right);
        auto l = 1 + lr;
        auto r = 1 + rl;
        auto b = max(max(lb, rb), max(l, r));
        return tuple(b, l, r);
    }
};
