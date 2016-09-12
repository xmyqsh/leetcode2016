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
