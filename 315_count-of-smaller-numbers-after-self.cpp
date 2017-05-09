class Solution {
private:
    struct segmentTreeNode {
        int start, end, count;
        segmentTreeNode *left, *right;
        segmentTreeNode(int s, int e, int cnt) : start(s), end(e), count(cnt), left(NULL), right(NULL) {}
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int start = nums[0], end = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            start = min(start, nums[i]);
            end = max(end, nums[i]);
        }
        segmentTreeNode* root = build(start, end);
        for (auto num : nums) modify(root, num, 1);
        for (auto num : nums) {
            result.push_back(query(root, start, num - 1));
            modify(root, num, -1);
        }
        return result;
    }
    segmentTreeNode* build(int start, int end) {
        segmentTreeNode* root = new segmentTreeNode(start, end, 0);
        if (start == end) return root;
        const int mid = start + (end - start) / 2;
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
        //root->count = root->left->count + root->right->count;
        return root;
    }
    void modify(segmentTreeNode* root, int num, int adder) {
        if (root->start == root->end) {
            root->count += adder;
            return;
        }
        const int mid = root->start + (root->end - root->start) / 2;
        if (num <= mid) modify(root->left, num, adder);
        else modify(root->right, num, adder);
        root->count = root->left->count + root->right->count;
    }
    int query(segmentTreeNode* root, int start, int end) {
        if (start > end) return 0;
        if (root->start >= start && root->end <= end) return root->count;
        const int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) return query(root->left, start, end);
        else if (start > mid) return query(root->right, start, end);
        return query(root->left, start, mid) + query(root->right, mid + 1, end);
    }
};

// Binary Index Tree
// with inputs compact
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        int hashVal = 1;
        for (int i = 0; i != nums2.size(); ++i)
            if (!mp.count(nums2[i]))
                mp[nums2[i]] = hashVal++;
        for (int i = 0; i != nums.size(); ++i)
            nums2[i] = mp[nums[i]];
        cnt.resize(hashVal);
        fill(cnt.begin(), cnt.end(), 0);
        for (auto num : nums2)
            modify(num, 1);
        vector<int> result;
        for (auto num : nums2) {
            modify(num, -1);
            result.push_back(query(num - 1));
        }
        return result;
    }
    void modify(int idx, int val) {
        do {
            cnt[idx] += val;
            idx += lowbit(idx);
        } while (idx < cnt.size());
    }
    int query(int idx) {
        int ret = 0;
        do {
            ret += cnt[idx];
            idx -= lowbit(idx);
        } while (idx > 0);
        return ret;
    }
    int lowbit(int n) {
        return (n & (n ^ (n - 1)));
    }
private:
    vector<int> cnt;
    unordered_map<int, int> mp;
};
