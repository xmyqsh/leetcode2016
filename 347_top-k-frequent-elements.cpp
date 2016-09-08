class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) ++mp[num];
        if (mp.size() == nums.size()) return nums;
        vector<int> result;
        priority_queue<pair<int, int> > pq;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) pq.push(make_pair(iter->second, iter->first));
        while (result.size() < k) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
