class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        travel(&result, ip, s, 0, 0);
        return result;
    }
    void travel(vector<string>* result, string ip, const string& s, int start, int step) {
        if (step == 4 && start == s.size()) {
            ip.resize(ip.size() - 1);
            result->push_back(ip);
            return;
        }
        if (s.size() - start > 3 * (4 - step)) return;
        if (s.size() - start < 4 - step) return;
        for (int i = start, num = 0; i < s.size(); ++i) {
            num = 10 * num + s[i] - '0';
            if (num > 255) break;
            ip.push_back(s[i]);
            travel(result, ip + '.', s, i + 1, step + 1);
            if (num == 0) break;
        }
    }
};
