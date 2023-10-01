class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        count=0
        st = str(num)
        for i in range(len(str(num))-k+1):
            x = int(st[i:i+k])
            if x!= 0 and num%x==0:
                count+=1
        return count