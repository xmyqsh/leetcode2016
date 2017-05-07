class Solution {
public:
    string reverseStr(string s, int k) {
        int maxE = s.size() - 1, b = 0, e = min(k - 1, maxE);
        do {
            int ib = b, ie = e;
            while (ib < ie)
                swap(s[ib++], s[ie--]);
            b += 2 * k;
            e = min(e + 2 * k, maxE);
        } while (b < s.size());
        return s;
    }
};
