class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size());
        if (nums.empty()) return result;
        stack<int> sk;
        unordered_map<int, int> mp;
        for (int i = 0; i != nums.size(); ++i) {
            while (!sk.empty() && nums[sk.top()] < nums[i]) {
                mp[sk.top()] = i;
                sk.pop();
            }
            sk.push(i);
        }
        for (int i = 0; i != nums.size() - 1; ++i) {
            while (!sk.empty() && nums[sk.top()] < nums[i]) {
                mp[sk.top()] = i;
                sk.pop();
            }
        }
        while (!sk.empty()) {
            mp[sk.top()] = -1;
            sk.pop();
        }
        for (int i = 0; i != nums.size(); ++i)
            if (mp[i] != -1) result[i] = nums[mp[i]];
            else result[i] = -1;
        return result;
    }
};
