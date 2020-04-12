class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> st;
        for (auto& sub : words) {
            for (auto& w : words) {
                if (sub.size() >= w.size()) continue;
                if (w.find(sub, 0) != string::npos) {
                    st.insert(sub);
                    break;
                }
            }
        }
        vector<string> result;
        for (auto& s : st) result.push_back(s);
        return result;
    }
};
