class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        a = set('qwertyuiop')
        b = set('asdfghjkl')
        c = set('zxcvbnm')
        ret = []
        for word in words:
            t = set(word.lower())
            if a & t == t or b & t == t or c & t == t:
                ret.append(word)
        return ret
