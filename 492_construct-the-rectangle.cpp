class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w) {
            --w;
        }
        return vector<int>{area / w, w};
    }
};
