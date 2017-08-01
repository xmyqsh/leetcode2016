class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        return nums if len(sum(nums, [])) != r * c else map(list, zip(*([iter(sum(nums, []))] * c)))
