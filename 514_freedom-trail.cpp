class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int rSize = ring.size(), kSize = key.size();
        vector<vector<int> > mp(26);
        for (int i = 0; i != ring.size(); ++i)
            mp[ring[i] - 'a'].push_back(i);
        vector<int> dp(rSize + 1, INT_MAX);
        dp[0] = 0;
        vector<int> startIdx(1, 0);
        for (int i = 0; i != kSize; ++i) {
            vector<int> nextDp(rSize + 1, INT_MAX);
            for (auto idx : mp[key[i] - 'a'])
                for (auto sIdx : startIdx)
                    nextDp[idx] = min(nextDp[idx], min((sIdx - idx + rSize) % rSize, (idx - sIdx + rSize) % rSize) + dp[sIdx]);
            startIdx = mp[key[i] - 'a'];
            swap(dp, nextDp);
        }
        int result = INT_MAX;
        for (auto elem : dp)
            result = min(result, elem);
        return result + kSize;
    }
};
