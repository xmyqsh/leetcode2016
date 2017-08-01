class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, ret = 0, 0
        for num in nums:
            if num:
                cnt += 1
            else:
                ret = max(ret, cnt)
                cnt = 0
        
        return max(ret, cnt)
