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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return travel(inorder, postorder, 0, 0, inorder.size());
    }
    
    TreeNode *travel(const vector<int>& inorder, const vector<int>& postorder, int bi, int bp, int len) {
        if (len == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[bp + len - 1]);
        int idx = bi;
        for (; inorder[idx] != postorder[bp + len - 1]; ++idx);
        root->left = travel(inorder, postorder, bi, bp, idx - bi);
        root->right = travel(inorder, postorder, idx + 1, bp + idx - bi, len - 1 - idx + bi);
        return root;
    }
};
