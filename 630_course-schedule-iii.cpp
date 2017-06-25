class Solution {
public:
    int scheduleCourse(vector<vector<int> >& courses) {
        for (int i = 0; i != courses.size(); ++i) courses[i].push_back(i);
        vector<vector<int> > coursesBK(courses.size());
        for (int i = 0; i != courses.size(); ++i)
            coursesBK[i] = courses[i];
        sort(courses.begin(), courses.end(), [](const vector<int>& course1, const vector<int>& course2) {
            return course1[0] < course2[0] || (course1[0] == course2[0] && course1[1] < course2[1]);
        });
        sort(coursesBK.begin(), coursesBK.end(), [](const vector<int>& course1, const vector<int>& course2) {
            return course1[1] < course2[1] || (course1[1] == course2[1] && course1[0] < course2[0]);
        });
        unordered_set<long long> st;
        int result = 0, tTotal = 0, maxEnd = 0;
        for (int i = 0; i != courses.size(); ++i) {
            vector<int>& course = courses[i];
            int tEnd = tTotal + course[0];
            maxEnd = max(maxEnd, course[1]);
            if (tEnd <= course[1] || (tEnd <= maxEnd && valid(coursesBK, course, st))) {
                ++result;
                tTotal = tEnd;
                st.insert(Hash(course[0], course[1], course[2]));
            }
        }
        return result;
    }
    long long Hash(long long idx, long long t, long long d) {
        return idx * 10000000000L + t * 100000 + d;
    }
    bool valid(vector<vector<int> >& coursesBK, vector<int>& course, unordered_set<long long>& st) {
        int tTotal = 0;
        st.insert(Hash(course[0], course[1], course[2]));
        for (int i = 0; i != coursesBK.size(); ++i) {
            if (st.count(Hash(coursesBK[i][0], coursesBK[i][1], coursesBK[i][2]))) {
                int tEnd = tTotal + coursesBK[i][0];
                if (tEnd > coursesBK[i][1]) {
                    st.erase(Hash(course[0], course[1], course[2]));
                    return false;
                }
                tTotal = tEnd;
            }
        }
        st.erase(Hash(course[0], course[1], course[2]));
        return true;
    }
};
