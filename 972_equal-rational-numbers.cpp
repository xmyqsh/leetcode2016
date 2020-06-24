class Solution {
public:
    bool isRationalEqual(string S, string T) {
        string PS(S), PT(T);
        while (!PS.empty() && !PT.empty() && PS[0] == PT[0]) {
            PS = PS.substr(1);
            PT = PT.substr(1);
        }
        if (!PS.empty() && !PT.empty() && isdigit(PS[0]) && isdigit(PT[0])
            && abs(stoi(PS) - stoi(PT)) == 1) return handleSpecialCase(PS, PT);
        bool hasSP = S.find_first_of('(', 0) != string::npos;
        bool hasTP = T.find_first_of('(', 0) != string::npos;
        if (hasSP && hasTP) return isRationalEqualWithP(S, T);
        // handling tailing zeros
        if (S.back() == '.') S.pop_back();
        if (T.back() == '.') T.pop_back();
        while (!S.empty() && S.back() == '0') S.pop_back();
        while (!T.empty() && T.back() == '0') T.pop_back();
        if (!S.empty() && S.back() == '.') S.pop_back();
        if (!T.empty() && T.back() == '.') T.pop_back();
        if (S.empty()) return allZero(T);
        if (T.empty()) return allZero(S);
        return S == T;
    }
    bool allZero(string S) {
        for (auto s : S) {
            if (s != '0' && s != '(' && s != ')' && s != '.') return false;
        }
        return true;
    }
    bool handleSpecialCase(string S, string T) {
        reverse(S.begin(), S.end());
        reverse(T.begin(), T.end());
        S.pop_back(); T.pop_back();
        if (!S.empty() && S.back() == '.') S.pop_back();
        if (!T.empty() && T.back() == '.') T.pop_back();
        int cntS0 = 0, cntS9 = 0;
        int cntT0 = 0, cntT9 = 0;
        bool hasSP = false, hasTP = false;
        for (auto s : S) {
            if (s == '0') ++cntS0;
            else if (s == '9') ++cntS9;
            else if (s != '(' && s != ')') return false;
            else hasSP = true;
        }
        for (auto t : T) {
            if (t == '0') ++cntT0;
            else if (t == '9') ++cntT9;
            else if (t != '(' && t != ')') return false;
            else hasTP = true;
        }
        if (cntS0 && cntS9) return false;
        if (cntT0 && cntT9) return false;
        if (cntS9 && cntT9) return false;
        if (!cntS9 && !cntT9) return false;
        if (cntS9 && !hasSP) return false;
        if (cntT9 && !hasTP) return false;
        return true;
    }
    bool isRationalEqualWithP(string S, string T) {
        reverse(S.begin(), S.end());
        reverse(T.begin(), T.end());
        while (S.back() != '(' && T.back() != '(' && S.back() == T.back()) {
            S.pop_back();
            T.pop_back();
        }
        if (S.back() != '(' && T.back() != '(') return false;
        //if (S.back() == '(' && T.back() == '(') return S == T;
        reverse(S.begin(), S.end());
        reverse(T.begin(), T.end());
        if (S[0] == '(') return isRepeatingPartEqual(S.substr(1, S.size() - 2), T);
        return isRepeatingPartEqual(T.substr(1, T.size() - 2), S);
    }
    bool isRepeatingPartEqual(string NS, string PS) {
        string BNS(NS);
        reverse(NS.begin(), NS.end());
        reverse(PS.begin(), PS.end());
        while (PS.back() != '(') {
            string BNS(NS);
            while (!BNS.empty() /*&& !PS.empty()*/ && BNS.back() == PS.back()) {
                BNS.pop_back();
                PS.pop_back();
            }
            if (PS.back() == '(') {
                NS += BNS;
                break;
            } else if (!BNS.empty()) return false;
        }
        PS = PS.substr(1, PS.size() - 2);
        while (!NS.empty()) {
            string BPS(PS);
            while (!BPS.empty() && !NS.empty() && BPS.back() == NS.back()) {
                BPS.pop_back();
                NS.pop_back();
            }
            if (!BPS.empty() && !NS.empty()) return false;
        }
        return true;
    }
};
/*
"0.(0)"
"0"
"0"
"0."
"1.0"
"1"
"0.(52)"
"0.5(25)"
"0.1666(6)"
"0.166(66)"
"1."
"1.000"
"0.999"
"1."
"0.9(9)"
"1."
"0.9(9)"
"1.(0)"
"12.9(9)"
"13.(0)"
"0.9(9)"
"0.(999)"
*/
