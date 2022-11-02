class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if(len(word1)!=len(word2)):
            return False;
        l1=dict()
        l2=dict()
        for i in word1:
            if i in l1:
                l1[i]+=1
            else:
                l1[i]=1
        for i in word2:
            if i in l2:
                l2[i]+=1
            else:
                l2[i]=1
        flag=False;
        
        if(l1.keys()==l2.keys() and sorted(l1.values())==sorted(l2.values())):
            return True
        else:
            return False