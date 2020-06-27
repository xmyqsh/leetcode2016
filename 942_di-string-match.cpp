class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> result; result.reserve(S.size() + 1);
        int b = 0, e = S.size();
        for (auto c : S) result.push_back(c == 'I' ? b++ : e--);
        result.push_back(b);
        return result;
    }
};
