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
    int findTilt(TreeNode* root) {
        int sumTilt = 0;
        findTilt(root, sumTilt);
        return sumTilt;
    }
    int findTilt(TreeNode* root, int& sumTilt) {
        if (!root) return 0;
        int leftSum = findTilt(root->left, sumTilt);
        int rightSum = findTilt(root->right, sumTilt);
        sumTilt += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
};
