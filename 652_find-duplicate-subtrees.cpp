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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> > mp;
        seralize(root, mp);
        vector<TreeNode*> result;
        for (auto& item : mp) {
            if (item.second.size() > 1)
                result.push_back(item.second[0]);
        }
        return result;
    }
    string seralize(TreeNode* root, unordered_map<string, vector<TreeNode*> >& mp) {
        if (!root) return "";
        string key = '(' + seralize(root->left, mp) + ')' + to_string(root->val) + '(' + seralize(root->right, mp) + ')';
        mp[key].push_back(root);
        return key;
    }
};

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
private:
    map<tuple<int, int, int>, int> mp;
    unordered_map<int, int> cnt;
    vector<TreeNode*> result;
    int id;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        id = 1;
        dfs(root);
        return result;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        tuple<int, int, int> tmp = {root->val, dfs(root->left), dfs(root->right)};
        if (!mp.count(tmp)) mp[tmp] = id++;
        if (++cnt[mp[tmp]] == 2) result.push_back(root);
        return mp[tmp];
    }
};
