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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> > mp;
        seralize(root, mp);
        vector<TreeNode*> result;
        for (auto& item : mp) {
            if (item.second.size() > 1)
                result.push_back(item.second[0]);
        }
        return result;
    }
    string seralize(TreeNode* root, unordered_map<string, vector<TreeNode*> >& mp) {
        if (!root) return "";
        string key = '(' + seralize(root->left, mp) + ')' + to_string(root->val) + '(' + seralize(root->right, mp) + ')';
        mp[key].push_back(root);
        return key;
    }
};
