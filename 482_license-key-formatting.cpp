class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int cnt = 0;
        for (auto c : S)
            if (isalnum(c))
                ++cnt;
        int i = 0, k = cnt / K;
        cnt %= K;
        stringstream ss;
        if (cnt) {
            while (cnt) {
                if (isalnum(S[i])) {
                    --cnt;
                    if (isalpha(S[i]))
                        ss << (char)(toupper(S[i]));
                    else
                        ss << (char)(S[i]);
                }
                ++i;
            }
            ss << '-';
        }
        while (k--) {
            cnt = K;
            while (cnt) {
                if (isalnum(S[i])) {
                    --cnt;
                    if (isalpha(S[i]))
                        ss << (char)(toupper(S[i]));
                    else
                        ss << (char)(S[i]);
                }
                ++i;
            }
            ss << '-';
        };
        string result = ss.str();
        result.pop_back();
        return result;
    }
};
