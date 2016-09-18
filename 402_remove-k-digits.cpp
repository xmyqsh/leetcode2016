class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        for (int i = 0, j; i != k; ++i) {
            for (j = 1; num[j - 1] <= num[j] && j != num.size(); ++j);
            if (j != num.size()) num.erase(j - 1, 1);
            else num.erase(num.size() - 1);
        }
        int i = 0;
        while (num[i] == '0') ++i;
        num.erase(0, i);
        return num.empty() ? "0" : num;
    }
};
