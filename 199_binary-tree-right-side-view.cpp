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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        travel(&result, root, 1);
        return result;
    }
    void travel(vector<int>* result, TreeNode* root, int level) {
        if (!root) return;
        if (result->size() < level) result->push_back(root->val);
        else (*result)[level - 1] = root->val;
        travel(result, root->left, level + 1);
        travel(result, root->right, level + 1);
    }
};
