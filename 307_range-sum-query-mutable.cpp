class NumArray {
private:
    struct segmentTreeNode {
        int start, end, sum;
        segmentTreeNode *left, *right;
        segmentTreeNode(int st, int e, int s) : start(st), end(e), sum(s), left(NULL), right(NULL) {}
    };
    segmentTreeNode* root;
public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) root = NULL;
        else root = build(nums, 0, nums.size() - 1);
    }

    segmentTreeNode* build(const vector<int>& nums, int start, int end) {
        segmentTreeNode* root = new segmentTreeNode(start, end, nums[end]);
        if (start == end) return root;
        const int mid = start + (end - start) / 2;
        root->left = build(nums, start, mid);
        root->right = build(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    void update(segmentTreeNode* root, int i, int val) {
        if (root->start == root->end) {
            root->sum = val;
            return;
        }
        const int mid = root->start + (root->end - root->start) / 2;
        if (i <= mid) update(root->left, i, val);
        else update(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }

    int sumRange(int i, int j) {
        if (!root || i > j) return 0;
        return sumRange(root, i, j);
    }

    int sumRange(segmentTreeNode* root, int start, int end) {
        if (root->start == start && root->end == end) return root->sum;
        const int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) return sumRange(root->left, start, end);
        if (start > mid) return sumRange(root->right, start, end);
        return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

// Binary Index Tree
class NumArray {
public:
    NumArray(vector<int> nums) {
        sum.resize(nums.size() + 1);
        numsBK.resize(nums.size());
        fill(numsBK.begin(), numsBK.end(), 0);
        fill(sum.begin(), sum.end(), 0);
        for (int i = 0; i != nums.size(); ++i)
            update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int idx = i + 1;
        do {
            sum[idx] += (val - numsBK[i]);
            idx += lowbit(idx);
        } while (idx < sum.size());
        numsBK[i] = val;
    }
    
    int sumRange(int i, int j) {
        return query(j) - query(i - 1);
    }
    
    int query(int i) {
        int ret = 0, idx = i + 1;
        do {
            ret += sum[idx];
            idx -= lowbit(idx);
        } while (idx > 0);
        return ret;
    }
    
    int lowbit(int n) {
        return (n & (n ^ (n - 1)));
    }
private:
    vector<int> sum;
    vector<int> numsBK;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
