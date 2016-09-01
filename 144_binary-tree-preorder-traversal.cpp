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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sk;
        if (root) sk.push(root);
        while (!sk.empty()) {
            root = sk.top();
            sk.pop();
            result.push_back(root->val);
            if (root->right) sk.push(root->right);
            if (root->left) sk.push(root->left);
        }
        return result;
    }
};
