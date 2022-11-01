class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        l=[0]*101
        for i in range(len(nums)):
            l[nums[i]]+=1
        sum=0
        for i in range(101):
            if(l[i]==1):
                sum+=i
        return sum