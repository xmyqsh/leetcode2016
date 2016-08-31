/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
    void connect(TreeLinkNode *root, TreeLinkNode *brother) {
        if (!root) return;
        root->next = brother;
        connect(root->left, root->right);
        connect(root->right, brother ? brother->left : NULL);
    }
};
