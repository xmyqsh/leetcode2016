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
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            root = q.front(); q.pop();
            if (!root) ss << '#' << ',';
            else {
                ss << to_string(root->val) << ',';
                q.push(root->left);
                q.push(root->right);
            }
        }
        string ret = ss.str();
        while (!ret.empty() && (ret.back() == ',' || ret.back() == '#')) ret.pop_back();
        cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        TreeNode dummy(-1);
        TreeNode** root = &dummy.left;
        queue<TreeNode**> q;
        q.push(root);
        int b, e;
        for (b = 0, e = 0; e != data.size(); ++e) {
            if (data[e] != ',') continue;
            root = q.front(); q.pop();
            if (data[b] == '#') *root = NULL;
            else {
                *root = new TreeNode(stoi(data.substr(b, e - b)));
                q.push(&(*root)->left);
                q.push(&(*root)->right);
            }
            b = e + 1;
        }
        root = q.front(); q.pop();
        *root = new TreeNode(stoi(data.substr(b, e - b)));
        return dummy.left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
