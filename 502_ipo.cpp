class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> low;
        multiset<pair<int, int> > high;
        for (int i = 0; i != Capital.size(); ++i) {
            if (Profits[i])
                if (Capital[i] <= W) low.push(Profits[i]);
                else high.insert(make_pair(Capital[i], Profits[i]));
        }
        while (!low.empty() && k--) {
            W += low.top(); low.pop();
            for (auto iter = high.begin(); iter != high.end() && iter->first <= W; iter = high.erase(iter))
                low.push(iter->second);
        }
        return W;
    }
};
