// TLE
class Solution {
public:
    int brokenCalc(int X, int Y) {
        queue<int> q;
        q.push(X);
        int cnt = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto n = q.front(); q.pop();
                if (n == Y) return cnt;
                else if (n > Y) q.push(n - 1);
                else {
                    q.push(n * 2);
                    q.push(n - 1);
                }
            }
            ++cnt;
        }
        return -1;
    }
};


class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cnt = 0;
        // When Y is larger than X, increment is meaningless, always divide
        while (Y > X) {
            if (Y & 1) ++Y; // This is make Divide be the invertor of Double
            else Y >>= 1;
            ++cnt;
        }
        return cnt + X - Y;
    }
};
/*
X --> (Double, Decrement) --> Y
X <-- (Divide, Increment) <-- Y

Divide: Y >> 1 or (Y + 1) >> 1
Increment: Y + 1
*/
