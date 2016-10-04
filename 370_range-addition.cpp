class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length + 1, 0);
        for (auto update : updates) {
            result[update[0]] += update[2];
            result[update[1] + 1] -= update[2];
        }
        for (int i = 1; i != result.size(); ++i)
            result[i] += result[i - 1];
        result.pop_back();
        return result;
    }
};
