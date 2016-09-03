class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 11) return result;
        bitset<1 << 20> bs1, bs2;
        int hash = 0, mask = (1 << 20) - 1;
        for (int i = 0; i < 10; ++i) hash = (hash << 2) | ctoh(s[i]);
        bs1.set(hash);
        for (int i = 10; i < s.size(); ++i) {
            hash = ((hash << 2) & mask) | ctoh(s[i]);
            if (bs2[hash]) continue;
            if (bs1[hash]) {
                result.push_back(s.substr(i - 9, 10));
                bs2.set(hash);
            } else bs1.set(hash);
        }
        return result;
    }
    int ctoh(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
};
