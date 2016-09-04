class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty()) return false;
        int i, cnt = 0, mask7 = 1 << 7, mask6 = 1 << 6;
        for (i = 0; i < data.size();) {
            if (cnt == 0) {
                int mk = mask7;
                while (cnt <= 4 && data[i] & mk) {
                    ++cnt;
                    mk >>= 1;
                }
                if (data[i] & mk) return false;
                if (cnt == 1) return false;
                ++i;
            } else {
                --cnt;
                while (cnt > 0 && i < data.size()) {
                    --cnt;
                    if (!(data[i] & mask7)) return false;
                    if (data[i] & mask6) return false;
                    ++i;
                }
            }
        }
        return cnt == 0;
    }
};
