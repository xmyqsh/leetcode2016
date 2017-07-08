class LogSystem {
public:
    LogSystem() {
        logs.clear();
    }
    
    void put(int id, string timestamp) {
        logs[timestamp].push_back(id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int end;
        if (gra[0] == 'Y') end = 4;
        else if (gra[0] == 'M' && gra[1] == 'o') end = 7;
        else if (gra[0] == 'D') end = 10;
        else if (gra[0] == 'H') end = 13;
        else if (gra[0] == 'M' && gra[1] == 'i') end = 16;
        else end = 19;
        
        vector<int> result;
        for (auto& log : logs) {
            if (valid(log.first, s, e, end))
                for (auto id : log.second)
                    result.push_back(id);
        }
        return result;
    }
private:
    bool valid(const string& key, const string& s, const string& e, int end) {
        for (int i = 0; i != end; ++i) {
            if (key[i] < s[i]) return false;
            if (key[i] > s[i]) break;
        }
        for (int i = 0; i != end; ++i) {
            if (key[i] > e[i]) return false;
            if (key[i] < e[i]) break;
        }
        return true;
    }
private:
    unordered_map<string, vector<int> > logs;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
