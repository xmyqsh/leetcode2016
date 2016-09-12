class NumArray {
public:
    NumArray(vector<int> &nums) {
        arrSum.resize(nums.size() + 1, 0);
        for (int i = 0; i != nums.size(); ++i)
            arrSum[i + 1] = arrSum[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return arrSum[j + 1] - arrSum[i];
    }
private:
    vector<int> arrSum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
