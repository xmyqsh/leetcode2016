/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (root || !sk.empty());
    }

    /** @return the next smallest number */
    int next() {
        while (root) {
            sk.push(root);
            root = root->left;
        }
        root = sk.top();
        sk.pop();
        int ret = root->val;
        root = root->right;
        return ret;
    }
private:
    stack<TreeNode*> sk;
    TreeNode* root;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
