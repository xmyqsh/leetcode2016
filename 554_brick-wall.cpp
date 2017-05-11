class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int width = 0;
        for (auto w : wall[0]) width += w;
        vector<int> mp(width, 0); // 1 ~ (width - 1)
        for (auto& line : wall) {
            int b = 0;
            for (auto width : line) {
                for (int i = b + 1; i != b + width; ++i)
                    ++mp[i];
                b += width;
            }
        }
        int result = wall.size();
        for (int i = 1; i != mp.size(); ++i)
            result = min(mp[i], result);
        return result;
    }
};

// : Memory Limit Exceeded
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int width = 0;
        for (auto w : wall[0]) width += w;
        vector<int> mp(width, wall.size()); // 1 ~ (width - 1)
        for (auto& line : wall) {
            int b = 0;
            for (int i = 0; i != line.size() - 1; ++i)
                --mp[b += line[i]];
        }
        int result = wall.size();
        for (int i = 1; i != mp.size(); ++i)
            result = min(mp[i], result);
        return result;
    }
};

// unordered_map
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int width = 0;
        for (auto w : wall[0]) width += w;
        unordered_map<int, int> mp;
        for (auto& line : wall) {
            int b = 0;
            for (int i = 0; i != line.size() - 1; ++i)
                ++mp[b += line[i]];
        }
        int result = 0;
        for (auto& elem : mp)
            result = max(elem.second, result);
        return wall.size() - result;
    }
};
