class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> path;
        dfs(result, path, num, 0);
        return result;
    }
    void dfs(vector<string>& result, vector<int>& path, int num, int bottom) {
        if (path.size() == num) {
            int hour = 0, minute = 0;
            for (auto n : path)
                if (n < 4) hour |= (1 << n);
                else minute |= (1 << (n - 4));
            if (hour < 12 && minute <= 59) {
                stringstream ss;
                ss << hour << ':' << (minute < 10 ? "0" : "") << minute;
                result.push_back(ss.str());
            }
            return;
        }
        if (bottom > 9) return;
        path.push_back(bottom);
        dfs(result, path, num, bottom + 1);
        path.pop_back();
        dfs(result, path, num, bottom + 1);
    }
};
