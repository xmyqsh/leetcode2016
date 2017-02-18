class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp1, mp2;
        fillMap(A, B, mp1);
        fillMap(C, D, mp2);
        int ret = 0;
        for (auto iter1 = mp1.begin(), iter2 = mp2.end(); iter1 != mp1.end(); ++iter1)
            if ((iter2 = mp2.find(-iter1->first)) != mp2.end())
                ret += iter1->second * iter2->second;
        return ret;
    }
    void fillMap(const vector<int>& A, const vector<int>& B, unordered_map<int, int>& mp) {
        for (auto a : A)
            for (auto b : B)
                ++mp[a + b];
    }
};
