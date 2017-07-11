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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<int> cnt;
        averageOfLevels(root, result, cnt, 1);
        for (int i = 0; i != result.size(); ++i)
            result[i] /= cnt[i];
        return result;
    }
    void averageOfLevels(TreeNode* root, vector<double>& result, vector<int>& cnt, int depth) {
        if (!root) return;
        if (result.size() < depth) {
            result.push_back(root->val);
            cnt.push_back(1);
        } else {
            result[depth - 1] += root->val;
            cnt[depth - 1]++;
        }
        averageOfLevels(root->left, result, cnt, depth + 1);
        averageOfLevels(root->right, result, cnt, depth + 1);
    }
};
