class Solution {
public:
    string validIPAddress(string IP) {
        bool isIPv4 = false, isIPv6 = false;
        if (IP.find('.', 0) != string::npos)
            isIPv4 = checkIPv4(IP);
        else if (IP.find(':', 0) != string::npos)
            isIPv6 = checkIPv6(IP);

        if (isIPv4) return "IPv4";
        else if (isIPv6) return "IPv6";
        else return "Neither";
    }
    bool checkIPv4(const string& IP) {
        int b = 0, e = 0, cnt = 0;
        while (e != IP.length()) {
            if ((e = IP.find('.', b)) == string::npos)
                e = IP.length();
            if (cnt == 4) return false;
            int len = e - b;
            if (len == 0 || len > 3) return false;
            string str = IP.substr(b, e - b);
            for (int i = b; i != e; ++i)
                if (!isdigit(IP[i])) return false;
            int num = stoi(str);
            if (num < 0 || num > 255) return false;
            if (itos(num).length() != len) return false;
            b = e + 1;
            ++cnt;
        }
        return cnt == 4;
    }
    bool checkIPv6(const string& IP) {
        int b = 0, e = 0, cnt = 0;
        while (e != IP.length()) {
            if ((e = IP.find(':', b)) == string::npos)
                e = IP.length();
            if (cnt == 8) return false;
            int len = e - b;
            if (len == 0 || len > 4) return false;
            for (int i = b; i != e; ++i) {
                if (!isalnum(IP[i])) return false;
                if (IP[i] >= 'g' && IP[i] <= 'z') return false;
                if (IP[i] >= 'G' && IP[i] <= 'Z') return false;
            }
            b = e + 1;
            ++cnt;
        }
        return cnt == 8;
    }
    string itos(int num) {
        stringstream ss;
        string str;
        ss << num;
        ss >> str;
        return str;
    }
};
