// Solution 1:
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, map<int, int>> mp;
        for (const auto& vote : votes) {
            for (int i = 0; i != vote.size(); ++i) ++mp[vote[i]][i];
        }
        vector<pair<char, string>> vp;
        for (auto item : mp) {
            stringstream ss;
            for (int i = 0; i != votes[0].size(); ++i) {
                string str_num = to_string(item.second[i]);
                ss << string(4 - str_num.size(), '0') << str_num;
            }
            vp.push_back(make_pair(item.first, ss.str()));
        }
        sort(vp.begin(), vp.end(), [](const auto& p1, const auto& p2) {
            return p1.second > p2.second ||
                  (p1.second == p2.second && p1.first < p2.first);
        });
        stringstream ss;
        for (const auto& p : vp) {
            ss << p.first;
        }
        return ss.str();
    }
};

// Solution 2:
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, map<int, int>> mp;
        for (const auto& vote : votes) {
            for (int i = 0; i != vote.size(); ++i) ++mp[vote[i]][i];
        }
        string ret(votes[0]);
        sort(ret.begin(), ret.end(), [&](char c1, char c2) {
            for (int i = 0; i != votes[0].size(); ++i) {
                if (mp[c1][i] > mp[c2][i]) return true;
                if (mp[c1][i] < mp[c2][i]) return false;
            }
            return c1 < c2;
        });
        return ret;
    }
};
