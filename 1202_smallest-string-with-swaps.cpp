class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        F.resize(s.size());
        iota(F.begin(), F.end(), 0);
        for (const auto& p : pairs) {
            F[father(p[0])] = father(p[1]);
        }
        vector<vector<char>> vv(s.size(), vector<char>());
        for (int i = 0; i != s.size(); ++i) {
            vv[father(i)].push_back(s[i]);
        }
        for (auto& v : vv) {
            sort(v.begin(), v.end(), greater<char>());
        }
        for (int i = 0; i != s.size(); ++i) {
            s[i] = vv[father(i)].back();
            vv[father(i)].pop_back();
        }
        return s;
    }
    int father(int x) {
        return x == F[x] ? x : F[x] = father(F[x]);
    }
private:
    vector<int> F;
};
