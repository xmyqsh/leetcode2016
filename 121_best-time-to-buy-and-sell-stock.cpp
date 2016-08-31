class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int bottom = prices[0], maxPro = 0;
        for (int i = 1; i < prices.size(); ++i) {
            bottom = min(bottom, prices[i]);
            maxPro = max(maxPro, prices[i] - bottom);
        }
        return maxPro;
    }
};
