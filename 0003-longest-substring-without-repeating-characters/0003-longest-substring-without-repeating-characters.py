class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res=0
        l=0
        cr = set()
        for r in range(len(s)):
            while s[r] in cr:
                cr.remove(s[l])
                l+=1
            cr.add(s[r])
            res=max(res,r-l+1)
        return res
