class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> count(ratings.size(), 0);
        for (int i = 1, inc = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                count[i] = inc++;
            else
                inc = 1;
        }
        for (int i = ratings.size() - 2, inc = 1; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                count[i] = max(count[i], inc++);
            else
                inc = 1;
        } 
        int sum = ratings.size();
        for (int i = 0; i < ratings.size(); ++i) sum += count[i];
        return sum;
    }
};
