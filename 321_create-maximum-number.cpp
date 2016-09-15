class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) return vector<int>();
        vector<int> result(1, -1);
        vector<vector<int> > dp1(nums1.size() + 1, vector<int>()), dp2(nums2.size() + 1, vector<int>());
        dp1[nums1.size()] = nums1; dp2[nums2.size()] = nums2;
        for (int i = nums1.size() - 1; i > 0; --i) {
            for (int j = 0; j < dp1[i + 1].size(); ++j)
                if (dp1[i + 1][j] >= dp1[i + 1][j + 1]) dp1[i].push_back(dp1[i + 1][j]);
                else while (++j != dp1[i + 1].size()) dp1[i].push_back(dp1[i + 1][j]);
            if (dp1[i].size() == dp1[i + 1].size()) dp1[i].pop_back();
        }
        for (int i = nums2.size() - 1; i > 0; --i) {
            for (int j = 0; j < dp2[i + 1].size(); ++j)
                if (dp2[i + 1][j] >= dp2[i + 1][j + 1]) dp2[i].push_back(dp2[i + 1][j]);
                else while (++j != dp2[i + 1].size()) dp2[i].push_back(dp2[i + 1][j]);
            if (dp2[i].size() == dp2[i + 1].size()) dp2[i].pop_back();
        }
        for (int i = 0, j = k; i <= k; ++i, --j) {
            if (i > nums1.size() || j > nums2.size()) continue;
            vector<int> cur = merge(dp1[i], dp2[j]);
            if (isLarge(cur, result)) swap(cur, result);
        }
        return result;
    }
    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> result(nums1.size() + nums2.size());
        int k = 0, i = 0, j = 0;
        while (i != nums1.size() && j != nums2.size())
            if (nums1[i] < nums2[j]) result[k++] = nums2[j++];
            else if (nums1[i] > nums2[j]) result[k++] = nums1[i++];
            else if (isLarge(vector<int>(nums1.begin() + i, nums1.end()), vector<int>(nums2.begin() + j, nums2.end())))
                result[k++] = nums1[i++];
            else result[k++] = nums2[j++];
        while (i != nums1.size()) result[k++] = nums1[i++];
        while (j != nums2.size()) result[k++] = nums2[j++];
        return result;
    }
    bool isLarge(const vector<int>& nums1, const vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return !isLarge(nums2, nums1);
        int i = 0, j = 0;
        while (i != nums1.size())
            if (nums1[i] < nums2[j]) return false;
            else if (nums1[i] > nums2[j]) return true;
            else { ++i; ++j; }
        return j == nums2.size();
    }
};
