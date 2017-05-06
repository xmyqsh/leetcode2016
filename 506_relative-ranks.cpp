class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank(nums);
        sort(rank.begin(), rank.end());
        unordered_map<int, string> mp;
        if (rank.size() - 1 >= 0)
            mp[rank[rank.size() - 1]] = "Gold Medal";
        if (rank.size() - 2 >= 0)
            mp[rank[rank.size() - 2]] = "Silver Medal";
        if (rank.size() - 3 >= 0)
            mp[rank[rank.size() - 3]] = "Bronze Medal";
        for (int i = rank.size() - 4; i >= 0; --i)
            mp[rank[i]] = itos(rank.size() - i);
        vector<string> result;
        for (auto num : nums)
            result.push_back(mp[num]);
        return result;
    }
    string itos(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }
};
