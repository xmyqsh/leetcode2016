class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i)
            ret += max(0, prices[i] - prices[i - 1]);
        return ret;
    }
};
