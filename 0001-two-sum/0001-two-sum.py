class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l={}
        t=[]
        for i in range(len(nums)):
            if (target-nums[i]) in l:
                t.append(i)
                t.append(l[target-nums[i]])
                return t
            else:
                l[nums[i]]=i
        return t
                