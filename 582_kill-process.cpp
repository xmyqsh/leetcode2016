class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int> > mp;
        for (int i = 0; i != pid.size(); ++i)
            mp[ppid[i]].push_back(pid[i]);
        queue<int> q;
        q.push(kill);
        vector<int> result;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            result.push_back(cur);
            if (mp.count(cur))
                for (auto elem : mp[cur])
                    q.push(elem);
        }
        return result;
    }
};
