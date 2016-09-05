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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int nLeft = 0, nRight = 0;
        TreeNode *left = root->left, *right = root->right;
        while (left) left = left->left, ++nLeft;
        while (right) right = right->right, ++nRight;
        if (nLeft == nRight) return pow(2, nLeft + 1) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
