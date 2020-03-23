class Solution {
public:
    string decodeAtIndex(string S, int K) {
        vector<pair<string, int>> si;
        decodeS(S, si);
        long long i = 0, cur = 0, prev = 0;
        vector<long long> period;
        for (; ; ++i) {
            period.push_back(prev + si[i].first.size());
            cur = (prev + si[i].first.size()) * si[i].second;
            if (cur < K) prev = cur;
            else {
                --K;
                int j;
                for (j = period.size() - 1; j != -1; --j) {
                    K %= period[j];
                    if (j != 0 && K >= period[j - 1] * si[j - 1].second) {
                        return string(1, si[j].first[K - period[j - 1] * si[j - 1].second]);
                    }
                }
                return string(1, si[0].first[K]);
            }
        }
        return "";
    }
    void decodeS(const string& s, vector<pair<string, int>>& si) {
        for (int b = 0, e = 0; b != s.size();) {
            while (s[e] >= 'a' && s[e] <= 'z') ++e;
            string sub = s.substr(b, e - b);
            int rep = 1;
            while (e != s.size() && s[e] >= '2' && s[e] <= '9') {
                if (INT_MAX / rep <= (s[e] - '0')) {
                    si.push_back(make_pair(sub, INT_MAX));
                    return;
                }
                rep *= (s[e++] - '0');
            }
            si.push_back(make_pair(sub, rep));
            b = e;
        }
    }
};
