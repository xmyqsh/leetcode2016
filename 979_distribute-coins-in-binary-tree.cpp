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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        auto [nodes, coins] = distributeCoins(root, moves);
        // assert(nodes == coins);
        return moves;
    }
    tuple<int, int> distributeCoins(TreeNode* root, int& moves) {
        if (!root) return {0, 0};
        auto [nodesL, coinsL] = distributeCoins(root->left, moves);
        auto [nodesR, coinsR] = distributeCoins(root->right, moves);
        moves += abs(nodesL - coinsL) + abs(nodesR - coinsR);
        return {1 + nodesL + nodesR, root->val + coinsL + coinsR};
    }
};
