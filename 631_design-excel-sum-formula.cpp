class Excel {
public:
    Excel(int H, char W) {
        Exl = vector<vector<int> >(H + 1, vector<int>(W - 'A' + 1, 0));
        fward.clear();
        bward.clear();
    }
    
    void set(int r, char c, int v) {
        int col = c - 'A', key = r * 26 + col;
        update(r, col, v);
        remove(key);
    }
    
    int get(int r, char c) {
        return Exl[r][c - 'A'];
    }

    int sum(int r, char c, vector<string> strs) {
        int col = c - 'A', key = r * 26 + col;
        remove(key);
        int ans = 0;
        for (auto str : strs) {
            int pos = str.find(':');
            int left = str[0] - 'A', right = str[pos + 1] - 'A';
            int top = stoi(str.substr(1)), bottom = stoi(str.substr(pos + 2));
            for (int i = top; i <= bottom; ++i) {
                for (int j = left; j <= right; ++j) {
                    ans += Exl[i][j];
                    int k = i * 26 + j;
                    ++fward[k][key];
                    bward[key].insert(k);
                }
            }
        }
        update(r, col, ans);
        return ans;
    }

private:
    void remove(int key) {
        if (bward.count(key)) {
            for (auto k : bward[key])
                fward[k].erase(key);
            bward[key].clear();
            bward.erase(key);
        }
    }

    void update(int r, int c, int v) {
        int prev = Exl[r][c];
        Exl[r][c] = v;
        queue<int> qKey, qDif;
        qKey.push(r * 26 + c);
        qDif.push(v - prev);
        while (!qKey.empty()) {
            int key = qKey.front(), dif = qDif.front();
            qKey.pop(); qDif.pop();
            if (!fward.count(key)) continue;
            for (auto& item : fward[key]) {
                int k = item.first, v = item.second;
                qKey.push(k); qDif.push(v * dif);
                Exl[k / 26][k % 26] += v * dif;
            }
        }
    }
private:
    unordered_map<int, unordered_map<int, int> > fward;
    unordered_map<int, unordered_set<int> > bward;
    vector<vector<int> > Exl;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
