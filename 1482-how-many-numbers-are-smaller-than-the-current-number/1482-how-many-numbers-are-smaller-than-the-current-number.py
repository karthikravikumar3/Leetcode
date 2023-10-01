class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = sorted(nums)
        lis = []
        for i in range(len(nums)):
            lis.append(n.index(nums[i]))
        return lis