class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n == 0) return 0;
        if (n % 2)
            return findMedianSortedArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), n / 2 + 1);
        else
            return (findMedianSortedArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), n / 2) + findMedianSortedArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), n / 2 + 1)) / 2.0;
    }
    
    typedef vector<int>::iterator Iter;
    double findMedianSortedArrays(Iter iter1, int n1, Iter iter2, int n2, int k) {
        if (n1 > n2)
            return findMedianSortedArrays(iter2, n2, iter1, n1, k);
        if (n1 == 0) return *(iter2 + k - 1);
        if (k == 1) return min(*iter1, *iter2);
        int m1 = min(n1, k / 2), m2 = k - m1;
        if (*(iter1 + m1 - 1) < *(iter2 + m2 - 1))
            return findMedianSortedArrays(iter1 + m1, n1 - m1, iter2, n2, k - m1);
        else
            return findMedianSortedArrays(iter1, n1, iter2 + m2, n2 - m2, k - m2);
    }
};
