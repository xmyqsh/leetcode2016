class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> st;
        int kinds = 0;
        for (auto candy : candies) {
            if (!st.count(candy)) {
                st.insert(candy);
                ++kinds;
            }
        }
        return min(kinds, (int)candies.size() / 2);
    }
};
