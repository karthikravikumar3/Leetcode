class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left,right = 0,len(numbers)-1
        lis=[]
        while left<right:
            if numbers[left]+numbers[right]==target:
                lis.append(left+1)
                lis.append(right+1)
                return lis
            elif numbers[left]+numbers[right]>target:
                right=right-1
            else:
                left=left+1
        return lis