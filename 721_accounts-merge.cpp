class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        pdsu = new DSU(10001);
        for (const auto& account : accounts) {
            auto& name = account[0];
            auto& firstEmail = account[1];
            for (int i = 2; i != account.size(); ++i) {
                auto& email = account[i];
                pdsu->uNion(firstEmail, email);
            }
        }
        unordered_map<string, vector<string>> mp;
        for (const auto& account : accounts) {
            auto& name = account[0];
            for (int i = 1; i != account.size(); ++i) {
                auto& email = account[i];
                auto& keyEmail = pdsu->find(move(email));
                if (!mp.count(keyEmail)) mp[keyEmail] = {name};
                mp[keyEmail].push_back(email);
            }
        }
        vector<vector<string>> result;
        for (auto& item : mp) {
            result.push_back(item.second);
            sort(result.back().begin() + 1, result.back().end());
            result.back().erase(unique(result.back().begin() + 1, result.back().end()), result.back().end());
        }
        return result;
    }
private:
    class DSU {
    public:
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n);
            fill(rank.begin(), rank.end(), 0);
            cnt = 0;
        }
        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void uNion(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else {
                ++rank[px];
                parent[py] = px;
            }
        }
        void uNion(const string& sx, const string& sy) {
            int x = getID(sx), y = getID(sy);
            uNion(x, y);
        }
        const string& find(const string& sx) {
            int x = getID(sx);
            return is[find(x)];
        }
        int getID(const string& sx) {
            if (!si.count(sx)) {
                si[sx] = cnt;
                is[cnt++] = sx;
            }
            return si[sx];
        }
    private:
        vector<int> parent, rank;
        unordered_map<string, int> si;
        unordered_map<int, string> is;
        int cnt;
    };
private:
    DSU* pdsu;
};
