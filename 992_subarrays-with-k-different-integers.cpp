class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        Window window1, window2;
        int ret = 0;
        // two windows, three pointers
        for (int b1 = 0, b2 = 0, e = 0; e != A.size(); ++e) {
            window1.insert(A[e]); window2.insert(A[e]);
            while (window1.size() > K) window1.erase(A[b1++]);
            while (window2.size() >= K) window2.erase(A[b2++]);
            //if (window1.size() == K) ret += b2 - b1;
            ret += b2 - b1;
        }
        return ret;
    }
public:
    class Window {
    public:
        Window() {
            sz = 0;
        }
        void insert(int x) {
            if (++mp[x] == 1) ++sz;
        }
        void erase(int x) {
            if (--mp[x] == 0) --sz;
        }
        int size() {
            return sz;
        }
    private:
        unordered_map<int, int> mp;
        int sz;
    };
};
