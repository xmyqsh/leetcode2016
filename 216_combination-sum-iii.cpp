class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> path;
        travel(&result, path, 1, 0, k, n);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>& path, int cur, int sum, int k, int n) {
        if (sum == n && path.size() == k) {
            result->push_back(path);
            return;
        }
        if (sum == n || path.size() == k) return;
        for (int i = cur; i < 10; ++i) {
            path.push_back(i);
            travel(result, path, i + 1, sum + i, k, n);
            path.pop_back();
        }
    }
};
