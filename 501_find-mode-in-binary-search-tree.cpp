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
    vector<int> findMode(TreeNode* root) {
        maxFreq = 0, curFreq = 0, curVal = (long)INT_MAX + 1;
        inorder(root);
        return result;
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (root->val == curVal) ++curFreq;
        else {
            curVal = root->val;
            curFreq = 1;
        }
        if (curFreq > maxFreq) {
            maxFreq = curFreq;
            result.clear();
            result.push_back(curVal);
        } else if (curFreq == maxFreq)
            result.push_back(curVal);
        inorder(root->right);
    }
private:
    vector<int> result;
    int maxFreq;
    int curFreq;
    long curVal;
};
