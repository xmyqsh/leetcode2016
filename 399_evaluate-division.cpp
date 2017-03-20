class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> mp;
        int cnt = 0;
        for (auto& eq : equations) {
            if (!mp.count(eq.first))
                mp[eq.first] = cnt++;
            if (!mp.count(eq.second))
                mp[eq.second] = cnt++;
        }
        vector<vector<double> > graph(cnt, vector<double>(cnt));
        vector<vector<int> > neighbors(cnt);
        vector<vector<int> > connected(cnt, vector<int>(cnt, 0));
        for (int i = 0; i != equations.size(); ++i) {
            int idx1 = mp[equations[i].first], idx2 = mp[equations[i].second];
            graph[idx1][idx2] = values[i];
            graph[idx2][idx1] = 1.0 / values[i];
            neighbors[idx1].push_back(idx2);
            neighbors[idx2].push_back(idx1);
            connected[idx1][idx2] = connected[idx2][idx1] = 1;
        }
        vector<double> result(queries.size(), -1.0);
        for (int i = 0; i != queries.size(); ++i) {
            vector<vector<int> > state(connected);
            if (!mp.count(queries[i].first) || !mp.count(queries[i].second)) continue;
            int idx1 = mp[queries[i].first], idx2 = mp[queries[i].second];
            if (idx1 == idx2) { result[i] = 1.0; continue; }
            queue<pair<int, double> > q;
            for (int j = 0; j != neighbors[idx1].size(); ++j) {
                int idxNext = neighbors[idx1][j];
                q.push(make_pair(idxNext, graph[idx1][idxNext]));
                state[idx1][idxNext] = state[idxNext][idx1] = 0;
            }
            while (!q.empty()) {
                pair<int, double> pairFrom = q.front(); q.pop();
                int idxFrom = pairFrom.first;
                double curValue = pairFrom.second;
                if (idxFrom == idx2) {
                    result[i] = curValue;
                    break;
                }
                for (int j = 0; j != neighbors[idxFrom].size(); ++j) {
                    int idxNext = neighbors[idxFrom][j];
                    if (state[idxFrom][idxNext]) {
                        q.push(make_pair(idxNext, curValue * graph[idxFrom][idxNext]));
                        state[idxFrom][idxNext] = state[idxNext][idxFrom] = 0;
                    }
                }
            }
        }
        return result;
    }
};
