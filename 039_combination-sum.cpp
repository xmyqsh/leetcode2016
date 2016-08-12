class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        travel(&result, &path, candidates, target, 0, 0);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>* path, const vector<int>& candidates, int target, int sum, int cur) {
        if (target == sum) {
            (*result).push_back(*path);
            return;
        }
        if (target < sum) return;
        for (int i = cur; i < candidates.size(); ++i) {
            (*path).push_back(candidates[i]);
            travel(result, path, candidates, target, sum + candidates[i], i);
            (*path).pop_back();
        }
    }
};
