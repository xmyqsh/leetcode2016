class Solution {
public:
    int numOfWays(int n) {
        vector<vector<int>> adj(12, vector<int>());
        adj[0]  = {1,2,3,5,10};
        adj[1]  = {0,3,6,8,11};
        adj[2]  = {0,3,6,7};
        adj[3]  = {1,2,7,10};
        adj[4]  = {0,6,8,9};
        adj[5]  = {0,6,7,9,10};
        adj[6]  = {1,2,4,5,11};
        adj[7]  = {2,3,5,11};
        adj[8]  = {1,4,9,10};
        adj[9]  = {4,5,8,11};
        adj[10] = {0,3,5,8,11};
        adj[11] = {1,6,7,9,10};
        vector<vector<int>> mp(12, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i != 12; ++i) {
            result += numOfWays(n - 1, adj, i, mp);
            result %= 1000000007;
        }
        return result;
    }
    int numOfWays(int n, const vector<vector<int>>& adj, int cur, vector<vector<int>>& mp) {
        if (n == 0) return 1;
        if (mp[cur][n]) return mp[cur][n];
        for (auto b : adj[cur]) {
            mp[cur][n] += numOfWays(n - 1, adj, b, mp);
            mp[cur][n] %= 1000000007;
        }
        return mp[cur][n];
    }
};
