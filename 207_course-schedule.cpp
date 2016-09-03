class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int> > graph;
        vector<int> count(numCourses, 0);
        for (auto iter = prerequisites.begin(); iter != prerequisites.end(); ++iter) {
            graph[iter->second].push_back(iter->first);
            count[iter->first]++;
        }
        int cnt = numCourses;
        for (int i = 0; i < numCourses; ++i)
            if (count[i] == 0)
                dfs(graph, count, i, cnt);
        return cnt == 0;
    }
    void dfs(unordered_map<int, vector<int> >& graph, vector<int>& count, int i, int& cnt) {
        --cnt;
        count[i] = -1;
        for (int j = 0; j < graph[i].size(); ++j)
            if (--count[graph[i][j]] == 0)
                dfs(graph, count, graph[i][j], cnt);
    }
};
