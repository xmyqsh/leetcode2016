// Stack: O(2*N)
//
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
    TreeNode* recoverFromPreorder(string S) {
        TreeNode Dummy(-1);
        TreeNode** root = &Dummy.left;
        stack<pair<TreeNode**, int>> sk;
        sk.push({root, 0});
        int d = 0, b = 0, idx = 0;
        while (!sk.empty()) {
            auto [root, d] = sk.top(); sk.pop();
            while (idx != min((int)S.size(), b + d) && S[idx] == '-') ++idx;
            if (idx != b + d) continue;
            int val = 0;
            while (idx != S.size() && S[idx] != '-') val = val * 10 + S[idx++] - '0';
            *root = new TreeNode(val);
            sk.push({&(*root)->right, d + 1});
            sk.push({&(*root)->left, d + 1});
            b = idx;
        }
        return Dummy.left;
    }
};

// Vector: O(N)
//
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
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> vecT;
        int b = 0, e = 0;
        for (; e != S.size(); ) {
            while (e != S.size() && S[e] == '-') ++e;
            int d = e - b;
            int val = 0;
            while (e != S.size() && S[e] != '-') val = val * 10 + S[e++] - '0';
            b = e;
            TreeNode* root = new TreeNode(val);
            if (vecT.size() == d) vecT.push_back(root);
            else vecT[d] = root;
            if (d) {
                if (vecT[d - 1]->left) vecT[d - 1]->right = root;
                else vecT[d - 1]->left = root;
            }
        }
        return vecT[0];
    }
};
