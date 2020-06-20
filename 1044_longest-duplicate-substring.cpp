class Solution {
public:
    int valid(const string& S, int w, vector<unsigned long long>& magic, vector<unsigned long long>& RKHashCache) {
        unordered_set<unsigned long long> st;
        unsigned long long RKHash = w == 1 ? 0 : RKHashCache[w - 2];
        for (int i = w - 1; i != S.size(); ++i) {
            RKHash = ((RKHash * 26) % 28379606267245447 + (S[i] - 'a')) % 28379606267245447;
            if (st.count(RKHash)) return i - (w - 1);
            st.insert(RKHash);
            RKHash += 28379606267245447 - ((S[i - (w - 1)] - 'a') * magic[w - 1]) % 28379606267245447;
            RKHash %= 28379606267245447;
        }
        return -1;
    }
    string longestDupSubstring(string S) {
        vector<unsigned long long> magic(S.size(), 0); magic[0] = 1;
        vector<unsigned long long> RKHashCache(S.size(), -1); RKHashCache[0] = S[0] - 'a';
        for (int i = 1; i != S.size(); ++i) {
            magic[i] = (magic[i - 1] * 26) % 28379606267245447;
            RKHashCache[i] = ((RKHashCache[i - 1] * 26) % 28379606267245447 + (S[i] - 'a')) % 28379606267245447;
        }
        int b = 0, e = S.size() - 1;
        while (b != e) {
            const int mid = (b + e + 1) / 2;
            if (valid(S, mid, magic, RKHashCache) != -1) b = mid;
            else e = mid - 1;
        }
        return e ? S.substr(valid(S, e, magic, RKHashCache), e) : "";
    }
};
