//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
public: 
vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 


class Solution {
  public:
      bool isverify(int adjr,int adjc,int n)
    {
        return adjr>=0&&adjr<n&&adjc>=0&&adjc<n;
    }

    bool isValid(int row, int col, int n, int m){
        return row>=0 && col >=0 && row<n && col<m;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        
        DisjointSet ds(grid.size()*grid.size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==0)continue;
                if(grid[i][j]==1){
                   int dx[]={-1,0,1,0};
                   int dy[]={0,-1,0,1};
                    for(int k=0;k<4;k++){
                        int adjr = i+dx[k];
                        int adjc = j+dy[k];
                        if(isValid(adjr,adjc,grid.size(),grid.size()) && grid[adjr][adjc]==1){
                            int celln = i*grid.size()+j;
                            int adjcelln = adjr*grid.size()+adjc;
                            ds.UnionBySize(celln,adjcelln);
                        }
                    }
                }
            }
        }
        int mx=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                
                if(grid[i][j]==1)continue;
                set<int> st;
                int dx[]={-1,0,1,0};
                   int dy[]={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int adjr = i+dx[k];
                    int adjc = j+dy[k];
                    if(isValid(adjr,adjc,grid.size(),grid.size()) ){
                        if(grid[adjr][adjc]==1){
                            
                        
                            //int celln = i*grid.size()+j;
                            int adjcelln = adjr*grid.size()+adjc;
                            st.insert(ds.findUPar(adjcelln));
                        }
                    }
                }
                int count=0;
                 for(auto it:st){
                count+=ds.size[it];
            }
                mx = max(mx,count+1);
                
            }
        }
        
        mx = max(mx,ds.size[ds.findUPar(grid.size()*(grid.size()-1))]);
        
        return mx;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends