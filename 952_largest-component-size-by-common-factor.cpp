// Dynamic growing Hash Union Find,  time: O(Nsqrt(W)), space: O(sqrt(W)) TLE
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        auto maxA = *max_element(A.begin(), A.end());
        vector<bool> prime(sqrt(maxA) + 1, true);
        vector<int> primes;
        unordered_map<int, int> p2idx;
        int i;
        for (i = 2; i * i < prime.size(); ++i) {
            if (prime[i]) {
                //p2idx[i] = primes.size();
                primes.push_back(i);
                for (int j = i * i; j < prime.size(); j += i) prime[j] = false;
            }
        }
        for (; i != prime.size(); ++i) if (prime[i]) { /*p2idx[i] = primes.size();*/ primes.push_back(i); }
        pdsu = new DSU(0);
        for (auto& a : A) {
            if (a == 1) {
                if (!p2idx.count(a)) {
                    p2idx[a] = pdsu->size();
                    pdsu->grow();
                }
                continue;
            }
            int lastPrime = -1;
            for (auto p : primes) {
                if (a % p == 0) {
                    if (!p2idx.count(p)) {
                        p2idx[p] = pdsu->size();
                        pdsu->grow();
                    }
                    while (a % p == 0) a /= p;
                    if (lastPrime != -1) pdsu->uNion(p2idx[lastPrime], p2idx[p]);
                    lastPrime = p;
                }
            }
            if (a != 1 && a != 0) {
                p2idx[a] = pdsu->size();
                primes.push_back(a);
                pdsu->grow();
                if (lastPrime != -1) pdsu->uNion(p2idx[lastPrime], p2idx[a]);
                lastPrime = a;
            }
            a = lastPrime;
        }
        int ret = 0;
        unordered_map<int, int> pCnt;
        for (auto p : A) ret = max(ret, ++pCnt[pdsu->find(p2idx[p])]);
        return ret;
    }
public:
    class DSU {
    public:
        DSU(int n) {
            parent.resize(n); rank.resize(n);
            iota(parent.begin(), parent.end(), 0);
            fill(rank.begin(), rank.end(), 0);
        }
        int size() {
            return parent.size();
        }
        void grow() {
            parent.push_back(parent.size());
            rank.push_back(0);
        }
        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        void uNion(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                ++rank[px];
                parent[py] = px;
            }
        }
    private:
        vector<int> parent, rank;
    };
private:
    DSU* pdsu;
};
/*
[99,68,70,77,35,52,25,62]
[99,68,70,77,35,52,53,25,62]
[99,68,70,77,35,52,53,25,62]
[2,3,4,5,6,7,8,9]
[4,6,15,35]
[20,50,9,63]
[2,3,6,7,4,12,21,39]
[1,2,3,4,5,6,7,8,9]
*/
