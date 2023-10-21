class Solution:
    def removeStars(self, s: str) -> str:
        li = []
        for i in s:
            if i=='*':
                li.pop(-1)
            else:
                li.append(i)
        return ''.join(li)