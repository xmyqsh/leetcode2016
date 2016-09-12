class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        travel(&result, path, n, k, 1);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>& path, int n, int k, int cur) {
        if (path.size() == k) {
            result->push_back(path);
            return;
        }
        for (int i = cur; i <= n; ++i) {
            path.push_back(i);
            travel(result, path, n, k, i + 1);
            path.pop_back();
        }
    }
};
