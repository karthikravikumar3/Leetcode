class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        mn = nums[0]
        sm=nums[0]
        i=1
        
        while(i<len(nums)):
            
            if(nums[i]>sm+nums[i]):
                sm=nums[i]
            else:
                sm+=nums[i]
            if(mn<sm):
                mn=sm
            i+=1
            
        return mn
            