class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;
        auto cmp = [&nums1, &nums2](const pair<int, int>& p1, const pair<int, int>& p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> minHeap(cmp);
        minHeap.emplace(0, 0);
        while (k-- && minHeap.size()) {
            auto pairIdx = minHeap.top(); minHeap.pop();
            result.emplace_back(nums1[pairIdx.first], nums2[pairIdx.second]);
            if (pairIdx.first + 1 != nums1.size()) minHeap.emplace(pairIdx.first + 1, pairIdx.second);
            if (pairIdx.first == 0 && pairIdx.second + 1 != nums2.size()) minHeap.emplace(0, pairIdx.second + 1);
        }
        return result;
    }
};
