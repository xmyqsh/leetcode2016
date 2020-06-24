class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto iter = mp[key].lower_bound(-timestamp);
        if (iter != mp[key].end()) return iter->second;
        return "";
    }
private:
    unordered_map<string, map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
