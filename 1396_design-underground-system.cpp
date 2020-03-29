class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        const auto& p = in[id];
        if (p.first > stationName) mp[stationName + p.first].push_back(t - p.second);
        else mp[p.first + stationName].push_back(t - p.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key;
        if (startStation > endStation) key = endStation + startStation;
        else key = startStation + endStation;
        double ret = 0;
        for (auto d : mp[key]) ret += d;
        return ret / mp[key].size();
    }
private:
    unordered_map<string, vector<int>> mp;
    unordered_map<int, pair<string, int>> in;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
