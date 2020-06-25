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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (root->val != voyage[0]) return {-1};
        vector<int> result;
        if (flipMatchVoyage(root, voyage, 0, voyage.size() - 1, result)) return result;
        return {-1};
    }
    bool flipMatchVoyage(TreeNode* root, vector<int>& voyage, int b, int e, vector<int>& result) {
        if (!root->left && !root->right) return b == e;
        if (!root->left && root->right->val != voyage[b + 1]) return false;
        if (!root->right && root->left->val != voyage[b + 1]) return false;
        int idxL = b + 1, idxR = b + 1;
        if (root->left) while (idxL <= e && voyage[idxL] != root->left->val) ++idxL;
        if (root->right) while (idxR <= e && voyage[idxR] != root->right->val) ++idxR;
        if (idxL == e + 1 || idxR == e + 1) return false;
        if (idxL != b + 1 && idxR != b + 1) return false;
        if (!root->left) {
            if (idxR != b + 1) return false;
            return flipMatchVoyage(root->right, voyage, idxR, e, result);
        } else if (!root->right) {
            if (idxL != b + 1) return false;
            return flipMatchVoyage(root->left, voyage, idxL, e, result);
        }
        if (idxL == b + 1) {
            return flipMatchVoyage(root->left, voyage, idxL, idxR - 1, result) &&
                   flipMatchVoyage(root->right, voyage, idxR, e, result);
        }
        result.push_back(root->val);
        return flipMatchVoyage(root->left, voyage, idxL, e, result) &&
               flipMatchVoyage(root->right, voyage, idxR, idxL - 1, result);
    }
};
