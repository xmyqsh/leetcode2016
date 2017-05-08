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
    int findBottomLeftValue(TreeNode* root) {
        int result, depthest = -1;
        dfs(root, result, depthest, 0);
        return result;
    }
    void dfs(TreeNode* root, int& result, int& depthest, int curdepth) {
        if (!root) return;
        if (curdepth > depthest) {
            result = root->val;
            depthest = curdepth;
        }
        dfs(root->left, result, depthest, curdepth + 1);
        dfs(root->right, result, depthest, curdepth + 1);
    }
};
