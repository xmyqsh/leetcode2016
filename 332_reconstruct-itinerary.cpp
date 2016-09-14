class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> result;
        unordered_map<string, multiset<string> > g;
        for (auto ticket : tickets) g[ticket.first].insert(ticket.second);
        travel("JFK", result, g);
        return vector<string>(result.rbegin(), result.rend());
    }
    void travel(string from, vector<string>& result, unordered_map<string, multiset<string> >& g) {
        while (!g[from].empty()) {
            string to = *(g[from].begin());
            g[from].erase(g[from].begin());
            travel(to, result, g);
        }
        result.push_back(from);
    }
};
