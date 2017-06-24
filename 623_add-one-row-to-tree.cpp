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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* rowNode = new TreeNode(v);
            rowNode->left = root;
            return rowNode;
        }
        addOneRow(root, v, d, 1);
        return root;
    }
    void addOneRow(TreeNode* root, int v, int d, int cur) {
        if (!root) return;
        if (cur + 1 == d) {
            TreeNode* rowNode1 = new TreeNode(v);
            rowNode1->left = root->left;
            root->left = rowNode1;

            TreeNode* rowNode2 = new TreeNode(v);
            rowNode2->right = root->right;
            root->right = rowNode2;
            return;
        }
        addOneRow(root->left, v, d, cur + 1);
        addOneRow(root->right, v, d, cur + 1);
    }
};
