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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        largestValues(result, root, 0);
        return result;
    }
    void largestValues(vector<int>& result, TreeNode* root, int depth) {
        if (!root) return;
        if (result.size() == depth)
            result.push_back(root->val);
        else
            result[depth] = max(result[depth], root->val);
        largestValues(result, root->left, depth + 1);
        largestValues(result, root->right, depth + 1);
    }
};
