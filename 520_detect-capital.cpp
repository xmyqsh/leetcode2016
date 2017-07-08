class Solution {
public:
    bool detectCapitalUse(string word) {
        int numCap = 0;
        for (auto ch : word)
            if (ch >= 'A' && ch <= 'Z')
                ++numCap;
        return numCap == 0 || numCap == word.size() || (numCap == 1 && word.size() != 1 && word[0] >= 'A' && word[0] <= 'Z');
    }
};
