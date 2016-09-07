class Solution {
public:
    int hIndex(vector<int>& citations) {
        int b = 0, e = citations.size() - 1;
        while (b <= e) {
            const int mid = b + (e - b) / 2;
            if (citations[mid] > citations.size() - mid) e = mid - 1;
            else if (citations[mid] < citations.size() - mid) b = mid + 1;
            else return citations.size() - mid;
        }
        return citations.size() - b;
    }
};
