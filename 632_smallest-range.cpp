class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp);
        vector<int> index(nums.size(), 0);
        
        int mx = -100000;
        for (int i = 0; i != nums.size(); ++i) {
            pq.push({nums[i][0], i});
            mx = max(mx, nums[i][0]);
        }
        int mn = pq.top().first;
        
        vector<int> result = {mn, mx};
        
        while (1) {
            int i = pq.top().second;
            pq.pop();
            ++index[i];
            if (index[i] == nums[i].size()) break;
            pq.push({nums[i][index[i]], i});
            mx = max(mx, nums[i][index[i]]);
            mn = pq.top().first;
            if (mx - mn < result[1] - result[0])
                result = {mn, mx};
        }
        return result;
    }
};
