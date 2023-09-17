class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        visit = set()
        islands = 0
        r,c = len(grid),len(grid[0])


        def bfs(r1,c1):
            q= collections.deque()
            visit.add((r1,c1))
            q.append((r1,c1))
            
            di=[[0,-1],[0,1],[1,0],[-1,0]]
            while q:
                row,col = q.popleft()
                for dr,dc in di:
                    l,m = row+dr,col+dc
                    if (l in range(r) and m in range(c) and grid[l][m]=="1" and (l,m) not in visit):
                        q.append((l,m))
                        visit.add((l,m))


        for i in range(r):
            for j in range(c):
                if grid[i][j]=="1" and (i,j) not in visit:
                    
                    bfs(i,j)
                    islands+=1
                    
        
        return islands
