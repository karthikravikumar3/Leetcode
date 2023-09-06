class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mx1=0
        mx2=0
        for i in range(len(prices)-1,-1,-1):
            mx1=max(mx1,prices[i])
            mx2=max(mx2,mx1-prices[i])
            #print(mx2)
        return mx2
        
