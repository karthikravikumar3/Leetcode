class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visit = [ [0]*len(grid[0]) for i in range(len(grid))]
        row = len(grid)
        col = len(grid[0])
        st=[]
        global_max=0
        count=0
        

        def dfs(i,j,mx):
            st.append((i,j))
            visit[i][j]=1
            count=0
            while st:
                count=count+1
                
                mx[0]=max(mx[0],count)
                print(mx[0])
                if grid[i][j]==1:
                    dir = [[0,1],[-1,0],[0,-1],[1,0]]
                    r,c=st.pop()
                    for dx,dy in dir:
                        r1 = r+dx
                        c1 = c+dy
                        if (r1 in range(row) and c1 in range(col) and grid[r1][c1]==1 and visit[r1][c1]==0):
                            st.append((r1,c1))
                            visit[r1][c1]=1

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if visit[i][j]==0 and grid[i][j]==1:
                    visit[i][j]==1
                    #count=0
                    local_max = [0]
                    dfs(i,j, local_max)
                    global_max = max(global_max,local_max[0])
    
        
        return global_max
        