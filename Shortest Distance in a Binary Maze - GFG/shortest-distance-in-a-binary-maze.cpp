//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),1e9));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({0,source});
        vis[source.first][source.second]=0;
        
        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(x==destination.first && y==destination.second){
                return dis;
            }
            for(int i=0;i<4;i++){
                int x1 = x+dx[i];
                int y1 = y+dy[i];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && grid[x1][y1]==1 ){
                    
                    
                        if(vis[x1][y1]>vis[x][y]+1){
                        vis[x1][y1]=vis[x][y]+1;
                        q.push({vis[x1][y1],{x1,y1}});
                        }
                    
                }
            }
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends