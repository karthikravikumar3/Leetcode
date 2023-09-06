class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r = 0,len(height)-1
        max1=0
        while l<r:
            area=min(height[l],height[r])*(r-l)
            #print(area)
            max1=max(max1,area)
            if(height[l]>height[r]):
                r-=1
            else:
                l+=1
            
        return max1
