class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        row = len(mat)
        col = len(mat[0])
        sum=0
        for i in range(0,row):
            for j in range(0,col):
                if i==j:
                    sum+=mat[i][j]
                if i+j==row-1 and not i==j:
                    print(str(i)+"-"+str(j))
                    sum+=mat[i][j]
        return sum
                