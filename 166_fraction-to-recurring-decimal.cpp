class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (!numerator) return "0";
        string str = (numerator ^ denominator) >> 63 ? "-" : "";
        numerator = abs(numerator);
        denominator = abs(denominator);
        str.append(to_string(numerator / denominator));
        if (!(numerator % denominator)) return str;
        str.push_back('.');
        unordered_map<int, int> mp;
        for (long long remainder = numerator % denominator; remainder; remainder %= denominator) {
            if (mp.count(remainder)) {
                str.insert(mp[remainder], 1, '(');
                str.push_back(')');
                break;
            }
            mp[remainder] = str.size();
            remainder *= 10;
            str.append(to_string(remainder / denominator));
        }
        return str;
    }
};
