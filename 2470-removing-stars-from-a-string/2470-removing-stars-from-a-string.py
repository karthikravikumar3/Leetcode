class Solution:
    def removeStars(self, s: str) -> str:
        li = []
        for i in s:
            if i=='*':
                li.pop()
            else:
                li+=i
        return ''.join(li)