class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> mp;
        ++mp[dis2(p1, p2)];
        ++mp[dis2(p2, p3)];
        ++mp[dis2(p3, p4)];
        ++mp[dis2(p4, p1)];
        ++mp[dis2(p1, p3)];
        ++mp[dis2(p2, p4)];
        if (mp.size() != 2) return false;
        for (auto& elem : mp)
            if (elem.second != 2 && elem.second != 4)
                return false;
        return true;
    }
    int dis2(const vector<int>& p1, const vector<int>& p2) {
        int diffx = p1[0] - p2[0], diffy = p1[1] - p2[1];
        return diffx * diffx + diffy * diffy;
    }
};

/*
p1p2  p2p3  p3p4 p4p1 p1p3 p2p4
*/
