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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        rangeSumBST(root, L, R, sum);
        return sum;
    }
    void rangeSumBST(TreeNode* root, int L, int R, int& sum) {
        if (!root) return;
        if (root->val < L) rangeSumBST(root->right, L, R, sum);
        else if (root->val > R) rangeSumBST(root->left, L, R, sum);
        else {
            sum += root->val;
            rangeSumBST(root->left, L, R, sum);
            rangeSumBST(root->right, L, R, sum);
        }
    }
};
