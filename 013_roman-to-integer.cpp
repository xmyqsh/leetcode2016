class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int cur = mp[s[0]], result = cur, prev;
        for (int i = 1; i < s.size(); ++i) {
            prev = cur;
            cur = mp[s[i]];
            result += cur;
            if (prev * 5 == cur || prev * 10 == cur)
                result -= 2 * prev;
        }
        return result;
    }
};
