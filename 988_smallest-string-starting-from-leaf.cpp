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
    string smallestFromLeaf(TreeNode* root) {
        string result, path;
        smallestFromLeaf(root, result, path);
        reverse(result.begin(), result.end());
        return result;
    }
    void smallestFromLeaf(TreeNode* root, string& result, string& path) {
        if (!root->left && !root->right) {
            path.push_back(root->val + 'a');
            if (result.empty()) {
                result = path;
                path.pop_back();
                return;
            }
            bool flag = true;
            int i, j;
            for (i = result.size() - 1, j = path.size() - 1; i != -1 && j != -1; --i, --j) {
                if (result[i] < path[j]) {
                    flag = false;
                    break;
                } else if (result[i] > path[j]) break;
            }
            if (flag && i != -1 || (i == -1 && j == -1)) result = path;
            path.pop_back();
            return;
        }
        path.push_back(root->val + 'a');
        if (root->left) smallestFromLeaf(root->left, result, path);
        if (root->right) smallestFromLeaf(root->right, result, path);
        path.pop_back();
    }
};
