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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sk;
        TreeNode *p = root, *q = NULL;
        do {
            while (p) {
                sk.push(p);
                p = p->left;
            }
            q = NULL;
            while (!sk.empty()) {
                p = sk.top();
                if (p->right == q) {
                    result.push_back(p->val);
                    sk.pop();
                    q = p;
                } else {
                    p = p->right;
                    break;
                }
            }
        } while (!sk.empty());
        return result;
    }
};
