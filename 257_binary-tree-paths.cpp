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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string path(to_string(root->val));
        travel(&result, path, root);
        return result;
    }
    void travel(vector<string>* result, string path, TreeNode* root) {
        if (!root->left && !root->right) {
            result->push_back(path);
            return;
        }
        path.append("->");
        if (root->left) travel(result, path + to_string(root->left->val), root->left);
        if (root->right) travel(result, path + to_string(root->right->val), root->right);
    }
};
