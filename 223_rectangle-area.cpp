class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        A = max(A, E);
        B = max(B, F);
        C = min(C, G);
        D = min(D, H);
        if (A >= C || B >= D) return area1 + area2;
        return area1 + area2 - (C - A) * (D - B);
    }
};
