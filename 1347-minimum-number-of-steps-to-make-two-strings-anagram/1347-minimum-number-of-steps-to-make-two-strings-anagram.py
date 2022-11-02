class Solution:
    def minSteps(self, s: str, t: str) -> int:
        l1=[0]*26
        l2=[0]*26
        for i in s:
            l1[ord(i)-ord('a')]+=1;
        for i in t:    
            l2[ord(i)-ord('a')]+=1;
        sum=0;
        for i in range(26):
            sum+=abs(l1[i]-l2[i])
        return int(sum/2)