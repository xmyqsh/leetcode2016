class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;
        for (auto n : arr) st.insert(n);
        unordered_map<int, int> mp;
        int r = 1;
        for (auto n : st) mp[n] = r++;
        vector<int> result(arr.size());
        for (int i = 0; i != arr.size(); ++i) {
            result[i] = mp[arr[i]];
        }
        return result;
    }
};
