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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        travel(&result, path, root, sum);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>& path, TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (sum == root->val && !root->left && !root->right) {
            result->push_back(path);
            path.pop_back();
            return;
        }
        travel(result, path, root->left, sum - root->val);
        travel(result, path, root->right, sum - root->val);
        path.pop_back();
    }
};
