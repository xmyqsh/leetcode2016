class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> parents((int)('z') + 1, 0);
        for (char ch = 'a'; ch != 'z' + 1; ++ch) parents[ch] = ch;
        for (const auto& e : equations) {
            if (e[1] == '=') {
                char a = e[0], b = e[3];
                uNion(parents, a, b);
            }
        }
        for (const auto& e : equations) {
            if (e[1] == '!') {
                char a = e[0], b = e[3];
                //if (a == b) return false;
                if (getP(parents, a) == getP(parents, b)) return false;
            }
        }
        return true;
    }
    char getP(vector<char>& parents, char a) {
        if (parents[a] == a) return a;
        return parents[a] = getP(parents, parents[a]);
    }
    void uNion(vector<char>& parents, char a, char b) {
        parents[getP(parents, a)] = getP(parents, b);
    }
};
