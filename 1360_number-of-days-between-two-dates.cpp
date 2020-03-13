class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int y1 = stoi(date1.substr(0, 4)), m1 = stoi(date1.substr(5, 2)), d1 = stoi(date1.substr(8, 2));
        int y2 = stoi(date2.substr(0, 4)), m2 = stoi(date2.substr(5, 2)), d2 = stoi(date2.substr(8, 2));
        int cnt1 = count(y1, m1, d1);
        int cnt2 = count(y2, m2, d2);
        return abs(cnt1 - cnt2);
    }
    int count(int Y, int M, int D) {
        unordered_set<int> st = {1,3,5,7,8,10,12};
        int cnt = 0;
        for (int y = 1971; y != Y; ++y) {
            if (isRun(y)) cnt += 366;
            else cnt += 365;
        }
        for (int m = 1; m != M; ++m) {
            if (m == 2) {
                if (isRun(Y)) cnt += 29;
                else cnt += 28;
            } else if (st.count(m)) cnt += 31;
            else cnt += 30;
        }
        cnt += (D - 1);
        return cnt;
    }
    int isRun(int y) {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }
};
