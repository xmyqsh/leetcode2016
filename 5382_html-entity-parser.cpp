class Solution {
public:
    string entityParser(string text) {
        int idx = 0;
        for (int i = 0; i != text.size(); ++i) {
            if (text[i] != '&') text[idx++] = text[i];
            else if (i + 3 < text.size() && text[i + 3] == ';' &&
                                            text[i + 2] == 't' &&
                                           (text[i + 1] == 'g' || text[i + 1] == 'l')) {
                text[idx++] = text[i + 1] == 'g' ? '>' : '<';
                i += 3;
            } else if (i + 4 < text.size() && text[i + 4] == ';' && text[i + 3] == 'p' &&
                                                                    text[i + 2] == 'm' &&
                                                                    text[i + 1] == 'a') {
                text[idx++] = '&';
                i += 4;
            } else if (i + 6 < text.size() && text[i + 6] == ';' && text[i + 5] == 'l' &&
                                                                    text[i + 4] == 's' &&
                                                                    text[i + 3] == 'a' &&
                                                                    text[i + 2] == 'r' &&
                                                                    text[i + 1] == 'f') {
                text[idx++] = '/';
                i += 6;
            } else if (i + 5 < text.size() && text[i + 5] == ';' && text[i + 3] == 'o') {
                if (text[i + 1] == 'q' && text[i + 2] == 'u' && text[i + 4] == 't') {
                    text[idx++] = '"';
                    i += 5;
                } else if (text[i + 1] == 'a' && text[i + 2] == 'p' && text[i + 4] == 's') {
                    text[idx++] = '\'';
                    i += 5;
                } else text[idx++] = text[i];
            } else text[idx++] = text[i];
        }
        return text.substr(0, idx);
    }
};
