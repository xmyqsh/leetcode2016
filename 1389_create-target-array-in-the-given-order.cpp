class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result(nums.size());
        for (int i = 0; i != nums.size(); ++i) {
            insert(result, index[i], nums[i]);
        }
        return result;
    }
    void insert(vector<int>& result, int id, int num) {
        int n = result.size();
        while (id + 1 != n) {
            result[n - 1] = result[n - 2];
            --n;
        }
        result[id] = num;
    }
};
