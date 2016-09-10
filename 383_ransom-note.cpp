class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(256, 0);
        for (auto ch : magazine) ++count[ch];
        for (auto ch : ransomNote) if (--count[ch] < 0) return false;
        return true;
    }
};
