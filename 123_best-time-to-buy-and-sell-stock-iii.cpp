class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> ltor(prices.size(), 0);
        vector<int> rtol(prices.size(), 0);
        for (int i = 1, bottom = prices[0]; i < prices.size(); ++i) {
            bottom = min(bottom, prices[i]);
            ltor[i] = max(ltor[i - 1], prices[i] - bottom);
        }
        for (int i = prices.size() - 2, upper = prices[prices.size() - 1]; i >= 0; --i) {
            upper = max(upper, prices[i]);
            rtol[i] = max(rtol[i + 1], upper - prices[i]);
        }
        int maxPro = 0;
        for (int i = 0; i < prices.size(); ++i)
            maxPro = max(maxPro, ltor[i] + rtol[i]);
        return maxPro;
    }
};
