class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return true;
        if (preorder[preorder.size() - 1] != '#') return false;
        preorder.push_back(',');
        int count = 1, b = 0, e;
        do {
            if (count <= 0) return false;
            e = preorder.find_first_of(',', b);
            if (preorder[e - 1] == '#') --count;
            else ++count;
            b = e + 1;
        } while (b != preorder.size());
        return count == 0;
    }
};
