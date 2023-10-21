class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        li = []
        li2 = []
        for i in s:
            if i=='#' and len(li)==0:
                continue
            elif i=='#' and len(li)!=0:
                li.pop(-1)
            else:
                li.append(i)
        
        for i in t:
            if i=='#' and len(li2)==0:
                continue
            elif i=='#' and len(li2)!=0:
                li2.pop(-1)
            else:
                li2.append(i)
        #print(li)
        #print(li2)
        return li2==li