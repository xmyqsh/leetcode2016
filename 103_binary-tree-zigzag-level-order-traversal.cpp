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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        dfs(root, &result, 1);
        for (int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }
    
    void dfs(TreeNode* root, vector<vector<int> >* result, int level) {
        if (!root) return;
        if (result->size() < level) result->push_back(vector<int>());
        (*result)[level - 1].push_back(root->val);
        dfs(root->left, result, level + 1);
        dfs(root->right, result, level + 1);
    }
};
