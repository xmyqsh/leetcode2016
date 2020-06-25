class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) return {0,1,2,3,4,5,6,7,8,9};
        vector<int> result;
        if (K == 0) {
            for (char c = '1'; c <= '9'; ++c) result.push_back(stoi(string(N, c)));
            return result;
        }
        string path;
        for (char c = '1'; c <= '9'; ++c) {
            path.push_back(c);
            dfs(result, path, N, K, 1, c);
            path.pop_back();
        }
        return result;
    }
    void dfs(vector<int>& result, string& path, int N, int K, int n, int cur) {
        if (n == N) {
            result.push_back(stoi(path));
            return;
        }
        char c = cur - K;
        if (c >= '0') {
            path.push_back(c);
            dfs(result, path, N, K, n + 1, c);
            path.pop_back();
        }
        c = cur + K;
        if (c <= '9') {
            path.push_back(c);
            dfs(result, path, N, K, n + 1, c);
            path.pop_back();
        }
    }
};
