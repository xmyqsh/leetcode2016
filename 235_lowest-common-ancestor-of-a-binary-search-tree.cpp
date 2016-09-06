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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool hasP = false, hasQ = false;
        return lowestCommonAncestor(root, p, q, hasP, hasQ);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool& hasP, bool& hasQ) {
        if (!root) return NULL;
        bool bkP = hasP, bkQ = hasQ;
        TreeNode* left = lowestCommonAncestor(root->left, p, q, hasP, hasQ);
        if (left) return left;
        swap(bkP, hasP); swap(bkQ, hasQ);
        TreeNode* right = lowestCommonAncestor(root->right, p, q, hasP, hasQ);
        if (right) return right;
        hasP |= bkP; hasQ |= bkQ;
        if (root == p) hasP = true;
        if (root == q) hasQ = true;
        if (hasP && hasQ) return root;
        return NULL;
    }
};
