class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i != order.size(); ++i) mp[order[i]] = i;
        for (int i = 1; i != words.size(); ++i) {
            auto w1 = words[i - 1];
            auto w2 = words[i];
            int j;
            for (j = 0; j != w1.size() && j != w2.size(); ++j) {
                if (mp[w1[j]] > mp[w2[j]]) return false;
                else if (mp[w1[j]] < mp[w2[j]]) break;
            }
            if (j == w2.size()) {
                if (j < w1.size()) return false;
            }
        }
        return true;
    }
};
