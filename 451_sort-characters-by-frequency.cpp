class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) ++mp[c];
        priority_queue<pair<int, char> > pq;
        for (auto& elem : mp)
            pq.push(make_pair(elem.second, elem.first));
        stringstream ss;
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            while (p.first--)
                ss << p.second;
        }
        return ss.str();
    }
};
