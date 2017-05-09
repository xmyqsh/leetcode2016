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
    TreeNode* convertBST(TreeNode* root) {
        int curSum = 0;
        convertBST(curSum, root);
        return root;
    }
    void convertBST(int& curSum, TreeNode* root) {
        if (!root) return;
        convertBST(curSum, root->right);
        curSum = (root->val += curSum);
        convertBST(curSum, root->left);
    }
};
