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
    int minCameraCover(TreeNode* root) {
        auto [withCam, withoutCam, withoutCover] = minCameraCover1(root);
        return min(withCam, withoutCam);
    }
    tuple<int, int, int> minCameraCover1(TreeNode* root) {
        // Corner case:
        // NULL node {1000, 0, 0} --> leaf node {1, 1000, 0} --> parent of leaf node --> {1, 2, 2000}
        // When root is leaf node, it cannot without camera
        // When root is parent of leaf node, it cannot uncover with its childern covered
        if (!root) return {1000, 0, 0};
        auto [withCamL, withoutCamL, withoutCoverL] = minCameraCover1(root->left);
        auto [withCamR, withoutCamR, withoutCoverR] = minCameraCover1(root->right);
        return {1 + min({withCamL, withoutCamL, withoutCoverL}) + min({withCamR, withoutCamR, withoutCoverR}),
                min(withCamL + min(withCamR, withoutCamR), withCamR + min(withCamL, withoutCamL)),
                withoutCamL + withoutCamR};
    }
};
