class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for (auto num : nums1) st.insert(num);
        vector<int> result;
        for (auto num : nums2) if (st.count(num)) result.push_back(num), st.erase(num);
        return result;
    }
};
