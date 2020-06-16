/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        if (!root) {
            ss << "#$";
            return ss.str();
        }
        ss << root->val << '$';
        ss << serialize(root->left);
        ss << serialize(root->right);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int e = -1;
        return deserialize(data, e);
    }
    TreeNode* deserialize(const string& data, int& e) {
        int b = e + 1;
        e = data.find('$', b);
        if (data[e - 1] == '#') return NULL;
        TreeNode* root = new TreeNode(stoi(data.substr(b, e - b)));
        root->left = deserialize(data, e);
        root->right = deserialize(data, e);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// non-recursion solution with serialization format same as leetcode official //
// which is the most compact version.                                         //
////////////////////////////////////////////////////////////////////////////////


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        int cnt = 0;
        if (root) {
            q.push(root);
            ++cnt;
        }
        stringstream ss;
        while (!q.empty() && cnt) {
            root = q.front(); q.pop();
            if (root) {
                --cnt;
                ss << to_string(root->val);
                q.push(root->left);
                q.push(root->right);
                if (root->left) ++cnt;
                if (root->right) ++cnt;
            } else {
                ss << 'N';
            }
            ss << '#';
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode Dummy(-1);
        TreeNode** pRoot = &Dummy.left;
        queue<TreeNode**> q;
        q.push(pRoot);
        for (int b = 0, e = 0; e != data.size(); ++e) {
            if (data[e] != '#') continue;
            pRoot = q.front(); q.pop();
            if (data[b] == 'N') {
                *pRoot = NULL;
            } else {
                *pRoot = new TreeNode(stoi(data.substr(b, e - b)));
                q.push(&(*pRoot)->left);
                q.push(&(*pRoot)->right);
            }
            b = e + 1;
        }
        return Dummy.left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
