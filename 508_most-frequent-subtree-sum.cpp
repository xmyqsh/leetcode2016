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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return vector<int>();
        unordered_map<int, int> mp;
        int mf = 0;
        mf = max(mf, ++mp[treeSum(root, mp, mf)]);
        vector<int> result;
        for (auto& elem : mp)
            if (elem.second == mf)
                result.push_back(elem.first);
        return result;
    }
    int treeSum(TreeNode* root, unordered_map<int, int>& mp, int& mf) {
        if (!root->left && !root->right)
            return root->val;
        int sumLeft = 0, sumRight = 0;
        if (root->left) {
            sumLeft = treeSum(root->left, mp, mf);
            mf = max(mf, ++mp[sumLeft]);
        }
        if (root->right) {
            sumRight = treeSum(root->right, mp, mf);
            mf = max(mf, ++mp[sumRight]);
        }
        return root->val + sumLeft + sumRight;
    }
};
