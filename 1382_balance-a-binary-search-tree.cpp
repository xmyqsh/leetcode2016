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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nums;
        inorder(root, nums);
        root = deInorder(nums, 0, (int)nums.size() - 1);
        return root;
    }
    void inorder(TreeNode* root, vector<TreeNode*>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root);
        inorder(root->right, nums);
    }
    TreeNode* deInorder(const vector<TreeNode*>& nums, int b, int e) {
        if (b > e) return NULL;
        int mid = (b + e) / 2;
        TreeNode* root = nums[mid];
        root->left = deInorder(nums, b, mid - 1);
        root->right = deInorder(nums, mid + 1, e);
        return root;
    }
};
