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
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced(root, height);
    }
    
    bool isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        int leftH, rightH;
        bool left = isBalanced(root->left, leftH);
        bool right = isBalanced(root->right, rightH);
        height = 1 + max(leftH, rightH);
        return left && right && abs(leftH - rightH) < 2;
    }
};
