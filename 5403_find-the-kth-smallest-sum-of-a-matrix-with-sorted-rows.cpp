class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        auto cmp = [](const auto& p1, const auto& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        int m = mat.size(), n = mat[0].size();
        int sum = 0;
        string key;
        for (int i = 0; i != m; ++i) {
            sum += mat[i][0];
            key += "00";
        }
        pq.push({key, sum});
        unordered_set<string> st;
        st.insert(key);
        while (!pq.empty() && k--) {
            auto p = pq.top(); pq.pop();
            key = p.first; sum = p.second;
            if (k == 0) return sum;
            for (int i = 0; i != 2 * m; i += 2) {
                string bk = key.substr(i, 2);
                int j = stoi(bk);
                if (j + 1 == n) continue;
                string strJ = to_string(j + 1);
                if (strJ.size() == 1) {
                    key[i] = '0'; key[i + 1] = strJ[0];
                } else {
                    key[i] = strJ[0]; key[i + 1] = strJ[1];
                }
                if (!st.count(key)) {
                    st.insert(key);
                    pq.push({key, sum - mat[i/2][j] + mat[i/2][j + 1]});
                }
                key[i] = bk[0];
                key[i + 1] = bk[1];
            }
        }
        return -1;
    }
};
