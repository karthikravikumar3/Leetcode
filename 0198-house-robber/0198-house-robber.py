class Solution:
    def rob(self, nums: List[int]) -> int:
        if(len(nums)==1):
            return nums[0]
        if(len(nums)==2):
            return max(nums[0],nums[1])
        cnt = [nums[0],max(nums[0],nums[1])]
        for i in range(2,len(nums)):
            cnt.append(max(cnt[i-1],cnt[i-2]+nums[i]))
        return cnt[len(nums)-1]
        