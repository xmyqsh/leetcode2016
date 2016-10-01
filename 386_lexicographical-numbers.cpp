class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i != 10; ++i)
            travel(&result, i, n);
        return result;
    }
    void travel(vector<int>* result, int cur, int n) {
        if (cur > n) return;
        result->push_back(cur);
        for (int i = 0; i != 10; ++i)
            travel(result, cur * 10 + i, n);
    }
};
