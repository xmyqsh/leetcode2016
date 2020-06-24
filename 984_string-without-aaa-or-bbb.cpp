class Solution {
public:
    
    string strWithout3a3b(int A, int B) {
        if (A < B) return strWithout3a3b(B, A, 'b', 'a');
        return strWithout3a3b(A, B, 'a', 'b');
    }
    string strWithout3a3b(int A, int B, char a, char b) {
        stringstream ss;
        int i = 0, j = 0;
        while (B && A > B) {
            ss << a << a << b;
            A -= 2;
            B -= 1;
        }
        while (B & A) {
            ss << a << b;
            --A; --B;
        }
        while (A) {
            ss << a;
            --A;
        }
        return ss.str();
    }
};
