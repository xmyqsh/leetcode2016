class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), [](int d1, int d2) {
            return d1 > d2;
        });
        if (digits[0] == 0) return "0";
        vector<vector<int>> mp(3, vector<int>());
        int sum = 0;
        for (auto d : digits) {
            mp[d % 3].push_back(d);
            sum += d;
        }
        int remain = sum % 3;
        if (remain == 0) return makeRet(digits, {});
        else if (remain == 1) {
            if (!mp[1].empty()) return makeRet(digits, {mp[1][mp[1].size() - 1]});
            else return makeRet(digits, {mp[2][mp[2].size() - 1], mp[2][mp[2].size() - 2]});
        } else {
            if (!mp[2].empty()) return makeRet(digits, {mp[2][mp[2].size() - 1]});
            else return makeRet(digits, {mp[1][mp[1].size() - 1], mp[1][mp[1].size() - 2]});
        }
        return "";
    }
    string makeRet(const vector<int>& digits, vector<int> st) {
        stringstream ss;
        for (auto d : digits) {
            if (inST(st, d)) continue;
            ss << d;
        }
        return ss.str();
    }
    bool inST(vector<int>& st, int d) {
        if (st.empty()) return false;
        if (st.size() == 1) {
            if (st[0] == d) {
                st.pop_back();
                return true;
            }
        } else { //st.size() == 2
            if (st[0] == d) {
                st[0] = st[1];
                st.pop_back();
                return true;
            } else if (st[1] == d) {
                st.pop_back();
                return true;
            }
        }
        return false;
    }
};
