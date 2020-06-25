/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int base = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            bool hasNULL = false;
            while (s--) {
                root = q.front(); q.pop();
                if (!root) {
                    hasNULL = true;
                    continue;
                } else if (hasNULL) return false;
                q.push(root->left);
                q.push(root->right);
            }
            if (hasNULL) {
                while (!q.empty()) {
                    root = q.front(); q.pop();
                    if (root) return false;
                }
            }
        }
        return true;
    }
};
