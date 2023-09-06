class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        lis=[]
        nums.sort()
        for i in range(len(nums)):
            l,r=i+1,len(nums)-1
            if i>0 and nums[i]==nums[i-1]:
                continue
            while l<r:
                tsum = nums[l]+nums[r]+nums[i]
                if tsum>0:
                    r-=1
                elif tsum<0:
                    l+=1
                else:
                    lis.append([nums[l],nums[r],nums[i]])
                    l+=1
                    while nums[l]==nums[l-1] and l<r:
                        l+=1
        return lis


        