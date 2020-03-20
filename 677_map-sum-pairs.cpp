class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for (const auto& item : mp) {
            if (item.first.size() < prefix.size()) continue;
            int i = 0;
            for (; i != prefix.size(); ++i) {
                if (prefix[i] != item.first[i]) break;
            }
            if (i != prefix.size()) continue;
            s += item.second;
        }
        return s;
    }
private:
    unordered_map<string, int> mp;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
