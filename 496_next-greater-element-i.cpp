class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if (findNums.empty()) return vector<int>();
        stack<int> sk;
        unordered_map<int, int> mp;
        for (int i = 0; i != nums.size(); ++i) {
            while (!sk.empty() && sk.top() < nums[i]) {
                mp[sk.top()] = nums[i];
                sk.pop();
            }
            sk.push(nums[i]);
        }
        while (!sk.empty()) {
            mp[sk.top()] = -1;
            sk.pop();
        }
        vector<int> result;
        for (auto num : findNums)
            result.push_back(mp[num]);
        return result;
    }
};
