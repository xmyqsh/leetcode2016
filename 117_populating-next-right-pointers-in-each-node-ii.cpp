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
        if (!root) return;
        TreeLinkNode dummy(-1);
        for (TreeLinkNode *cur = root, *prev = &dummy; cur; cur = cur->next) {
            if (cur->left) {
                prev->next = cur->left;
                prev = prev->next;
            }
            if (cur->right) {
                prev->next = cur->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};
