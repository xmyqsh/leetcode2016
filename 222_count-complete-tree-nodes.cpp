// O(NlogN)

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int nLeft = 0, nRight = 0;
        TreeNode *left = root->left, *right = root->right;
        while (left) left = left->left, ++nLeft;
        while (right) right = right->right, ++nRight;
        if (nLeft == nRight) return pow(2, nLeft + 1) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// O(logN)
// countNodes(root->left) at most once when root->right != NULL

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
    int countNodes(TreeNode* root) {
        unordered_map<TreeNode*, int> depthCache; depthCache[0] = 0;
        auto [depth, nodes] = countNodes1(root, depthCache);
        return nodes;
    }
    tuple<int, int> countNodes1(TreeNode* root, unordered_map<TreeNode*, int>& depthCache) {
        if (!root) return {0, 0};
        if (root->right) {
            auto [depthR, nodesR] = countNodes1(root->right, depthCache);
            if (getDepth(root->left, depthCache) == depthR) {
                return {1 + depthR, 1 + pow(2, depthR) - 1 + nodesR};
            }
            auto [depthL, nodesL] = countNodes1(root->left, depthCache);
            return {1 + depthL, 1 + nodesL + nodesR};
        }
        auto [depthL, nodesL] = countNodes1(root->left, depthCache);
        return {1 + depthL, 1 + nodesL};
    }
    int getDepth(TreeNode* root, unordered_map<TreeNode*, int>& depthCache) {
        if (depthCache.count(root)) return depthCache[root];
        return depthCache[root] = 1 + getDepth(root->left, depthCache);
    }
};
