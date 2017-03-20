class Solution {
public:
    int magicalString(int n) {
        string S = "122";
        int i = 2;
        while (S.size() < n)
            S.append(string(S[i++] - '0', S.back() ^ 3));
        return count(S.begin(), S.begin() + n, '1');
    }
};
