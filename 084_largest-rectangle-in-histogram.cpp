class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.empty()) return 0;
        height.push_back(-1);
        stack<int> sk;
        int maxArea = 0;
        for (int i = 0; i < height.size();) {
            if (sk.empty() || height[i] >= height[sk.top()]) {
                sk.push(i++);
            } else {
                int idx = sk.top();
                sk.pop();
                maxArea = max(maxArea, height[idx] * (sk.empty() ? i : i - sk.top() - 1));
            }
        }
        return maxArea;
    }
};
