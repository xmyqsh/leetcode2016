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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        vector<vector<int> > width;
        dfs(root, 0, width, 1);
        int result = 1;
        for (int i = 0; i != width.size(); ++i) {
            if (width[i].size() < 2) continue;
            result = max(result, width[i][width[i].size() - 1] - width[i][0] + 1);
        }
        return result;
    }
    void dfs(TreeNode* root, int w, vector<vector<int> >& width, int depth) {
        if (!root) return;
        if (width.size() != depth) width.push_back(vector<int>());
        width[depth - 1].push_back(w);
        dfs(root->left, 2 * w, width, depth + 1);
        dfs(root->right, 2 * w + 1, width, depth + 1);
    }
};
