// Time Limit Exceeded
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (!validArea(rectangles)) return false;
        if (sameCorner(rectangles)) return false;
        vector<int> mark(rectangles.size(), 0);
        int lastSize = rectangles.size(), curSize = rectangles.size();
        vector<int> newRec(4);
        do {
            lastSize = curSize;
            for (auto a = rectangles.begin(); a != rectangles.end(); ++a) {
                if (mark[a - rectangles.begin()]) continue;
                for (auto b = next(a); b != rectangles.end(); ++b) {
                    if (mark[b - rectangles.begin()]) continue;
                    if (canMerge(*a, *b, newRec)) {
                        (*a)[0] = newRec[0];
                        (*a)[1] = newRec[1];
                        (*a)[2] = newRec[2];
                        (*a)[3] = newRec[3];
                        mark[b - rectangles.begin()] = 1;
                        curSize--;
                    }
                    //if (lastSize != curSize) break;
                }
                //if (lastSize != curSize) break;
            }
        } while (lastSize != curSize);
        return curSize == 1;
    }
    bool validArea(const vector<vector<int> >& rectangles) {
        int area = 0, minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for (int i = 0; i < rectangles.size(); ++i) {
            area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            minx = min(minx, rectangles[i][0]);
            miny = min(miny, rectangles[i][1]);
            maxx = max(maxx, rectangles[i][2]);
            maxy = max(maxy, rectangles[i][3]);
        }
        return area == ((maxx - minx) * (maxy - miny));
    }
    bool sameCorner(const vector<vector<int> >& rectangles) {
        for (auto a = rectangles.begin(); a != rectangles.end(); ++a)
            for (auto b = next(a); b != rectangles.end(); ++b)
                if (((*a)[0] == (*b)[0] && (*a)[1] == (*b)[1]) || ((*a)[2] == (*b)[2] && (*a)[3] == (*b)[3]))
                    return true;
        return false;
    }
    bool canMerge(const vector<int>& rec1, const vector<int>& rec2, vector<int>& newRec) {
        if ((rec1[0] == rec2[0] && rec1[2] == rec2[2])) {
            newRec[0] = rec1[0];
            newRec[2] = rec1[2];
            if (rec1[3] == rec2[1]) {
                newRec[1] = rec1[1];
                newRec[3] = rec2[3];
                return true;
            } else if (rec1[1] == rec2[3]) {
                newRec[1] = rec2[1];
                newRec[3] = rec1[3];
                return true;
            } else {
                return false;
            }
        }
        if ((rec1[1] == rec2[1] && rec1[3] == rec2[3])) {
            newRec[1] = rec1[1];
            newRec[3] = rec1[3];
            if (rec1[2] == rec2[0]) {
                newRec[0] = rec1[0];
                newRec[2] = rec2[2];
                return true;
            } else if (rec1[0] == rec2[2]) {
                newRec[0] = rec2[0];
                newRec[2] = rec1[2];
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

// Accepted
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, int> > cornerCnt;
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        for (auto rect : rectangles) {
            minX = min(minX, rect[0]);
            minY = min(minY, rect[1]);
            maxX = max(maxX, rect[2]);
            maxY = max(maxY, rect[3]);
            if (!insertCorner(cornerCnt, rect[0], rect[1], 1)) return false;
            if (!insertCorner(cornerCnt, rect[0], rect[3], 2)) return false;
            if (!insertCorner(cornerCnt, rect[2], rect[3], 4)) return false;
            if (!insertCorner(cornerCnt, rect[2], rect[1], 8)) return false;
        }
        /*
        vector<int> validCorner(16, false);
        validCorner[3] = validCorner[6] = validCorner[9] = validCorner[12] = validCorner[15] = true;
        */
        for (auto elemX : cornerCnt) {
            int x = elemX.first;
            for (auto elemY : elemX.second) {
                int y = elemY.first, mask = elemY.second;
                if (!((x == minX || x == maxX) && (y == minY || y == maxY)) && /*!validCorner[mask]*/ (mask % 3)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool insertCorner(unordered_map<int, unordered_map<int, int> >& cornerCnt, int x, int y, int pos) {
        int& m = cornerCnt[x][y];
        if (m & pos) return false;
        m |= pos;
        return true;
    }
};
