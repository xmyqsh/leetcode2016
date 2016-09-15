class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size() / 2) {
            int maxPro = 0;
            for (int i = 1; i != prices.size(); ++i)
                if (prices[i] > prices[i - 1])
                    maxPro += prices[i] - prices[i - 1];
            return maxPro;
        }
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (auto price : prices) {
            for (int i = k; i > 0; --i) {
                sell[i] = max(sell[i], buy[i] + price);
                buy[i] = max(buy[i], sell[i - 1] - price);
            }
        }
        return sell[k];
    }
};
