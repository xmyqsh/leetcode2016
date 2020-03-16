/*
 * 这本质上是一道序列上的动态规划问题, 时间复杂度O(NlogN)。
 * 类似的问题有: 446_arithmetic-slices-ii-subsequence.cpp:
 *                  统计序列中的等差子数列的总数, O(N^2), 用**map**来辅助递推关系
 *               最长递增子序列(LIS), O(NlogN), 用**二分查找**从O(N^2)优化到O(NlogN)
 * 本题用**优先队列**辅助递推关系
 *
 * 总结来看：子序列上的动态规划问题，状态建模很简单，就是一维数组上以i元素结尾的子数组的解。
 *           难点在于递推公式的表达，需要借助额外的算法(map, 二分，优先队列)来辅助递推关系的实现，
 *           没有固定的套路，必需具体问题具体分析。
 *
 * 怎么确定要用DP解这道题：1. 看数据量，10^5基本限制在了O(N)和O(NlogN)了,
 *                            候选算法：排序，优先队列/堆查找，二分查找，一维DP，贪心
 *                         2. 看问题类型：子序列问题+卡时间，锁定一维DP配合其它算法
 * */
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int id1, int id2) {
            return efficiency[id1] > efficiency[id2];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ret = 0;
        for (auto id : idx) {
            pq.push(speed[id]);
            sum += speed[id];
            ret = max(ret, sum * efficiency[id]);
            if (pq.size() == k) {
                sum -= pq.top(); pq.pop();
            }
        }
        return (ret % 1000000007);
    }
};
