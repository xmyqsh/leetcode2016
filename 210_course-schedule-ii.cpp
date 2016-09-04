class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result, count(numCourses, 0);
        unordered_map<int, vector<int> > graph;
        for (auto iter = prerequisites.begin(); iter != prerequisites.end(); ++iter) {
            graph[iter->second].push_back(iter->first);
            count[iter->first]++;
        }
        for (int i = 0; i < numCourses; ++i)
            if (count[i] == 0)
                dfs(&result, count, graph, i);
        return result.size() == numCourses ? result : vector<int>();
    }
    void dfs(vector<int>* result, vector<int>& count, unordered_map<int, vector<int> >& graph, int i) {
        result->push_back(i);
        count[i] = -1;
        for (auto iter = graph[i].begin(); iter != graph[i].end(); ++iter)
            if (--count[*iter] == 0)
                dfs(result, count, graph, *iter);
    }
};
