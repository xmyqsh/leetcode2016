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
    int kthSmallest(TreeNode* root, int k) {
        int ret = -1, count = 0;
        travel(root, count, ret, k);
        return ret;
    }
    void travel(TreeNode* root, int& count, int& ret, int k) {
        if (!root) return;
        travel(root->left, count, ret, k);
        ++count;
        if (count == k) {
            ret = root->val;
            return;
        } else {
            travel(root->right, count, ret, k);
        }
    }
};
