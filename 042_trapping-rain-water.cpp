class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int maxInd = 0;
        for (int i = 0; i < height.size(); ++i)
            if (height[i] > height[maxInd])
                maxInd = i;
        int result = 0;
        for (int i = 1, peek = height[0]; i < maxInd; ++i)
            if (height[i] < peek) result += peek - height[i];
            else peek = height[i];
        for (int i = height.size() - 2, peek = height[height.size() - 1]; i > maxInd; --i)
            if (height[i] < peek) result += peek - height[i];
            else peek = height[i];
        return result;
    }
};
