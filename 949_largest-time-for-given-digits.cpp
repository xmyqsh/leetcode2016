class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        stringstream ss;
        bool all0 = true;
        for (auto a : A) {
            ss << a;
            if (a) all0 = false;
        }
        if (all0) return "00:00";
        string candi(ss.str());
        string best("0000");
        for (int i = 0; i != 24; ++i) {
            next_permutation(candi.begin(), candi.end());
            if (valid(candi) && candi > best) best = candi;
        }
        best.insert(best.begin() + 2, ':');
        return best == "00:00" ? "" : best;
    }
    bool valid(const string& candi) {
        int h = stoi(candi.substr(0, 2));
        int m = stoi(candi.substr(2));
        return h < 24 && m < 60;
    }
};
