class Solution(object):
    def isPalindrome(self, s):
        str=""
        for c in s:
            if(c.isalnum()):
                str+=c
        l,r=0,len(str)-1
        while l<r:
            if str[l].lower()!=str[r].lower():
                return False
            else:
                l+=1
                r-=1
        return True
        