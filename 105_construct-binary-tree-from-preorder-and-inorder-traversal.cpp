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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        return buildTree(preorder, inorder, 0, 0, preorder.size());
    }
    TreeNode *buildTree(const vector<int>& preorder, const vector<int>& inorder, int bp, int bi, int len) {
        if (len == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[bp]);
        int idx = bi;
        for (; inorder[idx] != preorder[bp]; ++idx);
        root->left = buildTree(preorder, inorder, bp + 1, bi, idx - bi);
        root->right = buildTree(preorder, inorder, bp + 1 + idx - bi, idx + 1, len - 1 - idx + bi);
        return root;
    }
};
