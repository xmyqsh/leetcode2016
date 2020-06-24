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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while (!q.empty()) {
            auto [root, row, col] = q.front(); q.pop();
            mp[col][row].push_back(root->val);
            if (root->left) q.push({root->left, row + 1, col - 1});
            if (root->right) q.push({root->right, row + 1, col + 1});
        }
        vector<vector<int>> result; result.reserve(mp.size());
        for (auto& col : mp) {
            result.push_back({});
            for (auto& item : col.second) {
                sort(item.second.begin(), item.second.end());
                for (auto n : item.second) result.back().push_back(n);
            }
        }
        return result;
    }
    void verticalTraversal(TreeNode* root, map<int, vector<int>>& mp, int x, int y) {
        if (!root) return;
        mp[y].push_back(root->val);
        verticalTraversal(root->left, mp, x + 1, y - 1);
        verticalTraversal(root->right, mp, x + 1, y + 1);
    }
};
