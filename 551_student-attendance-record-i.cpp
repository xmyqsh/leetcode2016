class Solution {
public:
    bool checkRecord(string s) {
        int cntL = 0, cntA = 0, i = 0;
        for (; i != s.size(); ++i) {
            if (s[i] == 'L') {
                if (++cntL == 3)
                    break;
            } else
                cntL = 0;
            if (s[i] == 'A')
                if (++cntA == 2)
                    break;
        }
        return i == s.size();
    }
};
