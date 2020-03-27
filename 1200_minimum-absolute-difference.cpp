class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int cur = INT_MAX;
        for (int i = 1; i != arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < cur) {
                cur = diff;
                result = {{arr[i - 1], arr[i]}};
            } else if (diff == cur) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
