class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp; mp[0] = 1;
        int sum = 0, ret = 0;
        for (int i = 0; i != A.size(); ++i) {
            sum = (sum + A[i]) % K;
            if (sum < 0) sum += K;
            auto iter = mp.find(sum);
            if (iter != mp.end()) ret += iter->second;
            ++mp[sum];
        }
        return ret;
    }
};
