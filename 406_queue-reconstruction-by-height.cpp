class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        vector<pair<int, int> > result;
        for (auto p : people)
            result.insert(result.begin() + p.second, p);
        return result;
    }
};
