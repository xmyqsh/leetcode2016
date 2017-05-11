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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode dummy(-1);
        TreeNode *prev = &dummy, *cur = root;
        prev->left = root;
        while (cur && cur->val != key) {
            prev = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (!cur) return root;
        if (!cur->left) {
            if (prev->left == cur) prev->left = cur->right;
            else prev->right = cur->right;
            delete cur;
        } else {
            TreeNode* tPrev = cur, *tCur = cur->left;
            while (tCur->right) {
                tPrev = tCur;
                tCur = tCur->right;
            }
            if (tPrev->left == tCur) {
                tCur->right = cur->right;
                if (prev->left == cur) prev->left = tCur;
                else prev->right = tCur;
                delete cur;
            } else {
                tPrev->right = tCur->left;
                cur->val = tCur->val;
                delete tCur;
            }
        }
        return dummy.left;
    }
};
