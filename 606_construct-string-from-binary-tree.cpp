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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        stringstream ss;
        ss << t->val;
        if (left.empty() && right.empty()) return ss.str();
        if (right.empty()) {
            ss << '(' << left << ')';
            return ss.str();
        }
        ss << '(' << left << ')' << '(' << right << ')';
        return ss.str();
    }
};
