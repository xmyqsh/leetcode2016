class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        return m * n if not ops else min([op[0] for op in ops]) * min([op[1] for op in ops])
