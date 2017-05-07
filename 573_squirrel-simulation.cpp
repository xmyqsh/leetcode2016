class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int result = 0, minPath = height + width;
        for (int i = 0; i != nuts.size(); ++i) {
            int disTree = distance(tree, nuts[i]);
            int disSqui = distance(squirrel, nuts[i]);
            result += 2 * disTree;
            minPath = min(minPath, disSqui - disTree);
        }
        return result + minPath;
    }
    int distance(vector<int>& pos1, vector<int>& pos2) {
        return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1]);
    }
};
