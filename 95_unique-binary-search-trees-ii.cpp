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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) {
            result.push_back(NULL);
        } else {
            for (int k = begin; k <= end; ++k) {
                vector<TreeNode*> left = generateTrees(begin, k - 1);
                vector<TreeNode*> right = generateTrees(k + 1, end);
                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* root = new TreeNode(k);
                        root->left = l;
                        root->right = r;
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
};
