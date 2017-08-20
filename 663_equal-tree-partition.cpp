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
    bool checkEqualTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return false;
        unordered_set<int> st;
        int sum = calcSum(root, st);
        if (sum & 1) return false;
        return st.count(sum >> 1);
    }
    int calcSum(TreeNode* root, unordered_set<int>& st) {
        if (!root) return 0;
        int leftSum = calcSum(root->left, st);
        int rightSum = calcSum(root->right, st);
        st.insert(leftSum);
        st.insert(rightSum);
        return root->val + leftSum + rightSum;
    }
};
