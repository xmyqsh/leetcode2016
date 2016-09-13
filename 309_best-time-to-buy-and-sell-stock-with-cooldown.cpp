class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> buy(prices.size()), sell(prices.size()), rest(prices.size());
        buy[0] = -prices[0]; sell[0] = 0; rest[0] = 0;
        for (int i = 1; i != prices.size(); ++i) {
            buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
            rest[i] = max(rest[i - 1], sell[i - 1]);
        }
        return max(max(buy[prices.size() - 1], sell[prices.size() - 1]), rest[prices.size() - 1]);
    }
};
