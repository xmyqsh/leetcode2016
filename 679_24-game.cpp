// Back trace
class Solution(object):
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 0: return False
        if len(nums) == 1: return abs(nums[0] - 24) < 1e-6
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i == j: continue
                B = [nums[k] for k in xrange(len(nums)) if i != k != j]
                for op in [truediv, mul, add, sub]:
                    if (op is mul or op is add) and i > j: continue       # cut branch
                    if op is not truediv or nums[j] != 0:
                        B.append(op(nums[i], nums[j]))
                        if self.judgePoint24(B): return True
                        B.pop()
        return False
