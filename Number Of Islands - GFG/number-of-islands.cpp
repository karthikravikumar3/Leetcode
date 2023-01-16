//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
vector<int> rank,size,parent;
public:
	


	DisjointSet(int n){
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++)parent[i]=i;

	}

	int findUPar(int node){
		if(node==parent[node])
		    return node;
		return parent[node] =findUPar(parent[node]);
	}
	//UnionByRank code is not working properly
	void UnionByRank(int NodeU,int NodeV){
		int ulp_u=findUPar(NodeU);
		int ulp_v=findUPar(NodeV);
		if(findUPar(NodeU)==findUPar(NodeV))return;
		if(rank[NodeU]>rank[NodeV]){
			parent[NodeV]=ulp_u;
		}
		else if(rank[NodeU]<rank[NodeV]){
			parent[NodeU]=ulp_v;
		}
		else{
			parent[findUPar(NodeV)]=ulp_u;
			rank[ulp_u]+=1;
		}

	}

	void UnionBySize(int NodeU, int NodeV){
		if(findUPar(NodeU)==findUPar(NodeV))return;
		if(size[NodeU]>size[NodeV]){
			parent[NodeV]=findUPar(NodeU);
			size[NodeU]+=findUPar(NodeV);
		}
		else {
			parent[findUPar(NodeU)]=findUPar(NodeV);
			size[NodeV]+=findUPar(NodeU);
		}
		
	}
};
class Solution {
  public:
    bool isValid(int x1,int y1, int row, int col){
        if(x1>=0 && y1>=0 && x1<row && y1<col){
            return true;
        }
        return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        DisjointSet ds(n*m);
        int cnt=0;
        vector<int> ans;
        for(int i=0;i<operators.size();i++){
            int x = operators[i][0];
            int y = operators[i][1];
            if(vis[x][y]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[x][y]=1;
            cnt++;
            
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            for(int j=0;j<4;j++){
                int x1 = x+dx[j];
                int y1 = y+dy[j];
                if(isValid(x1,y1,n,m)){
                    
                    if(vis[x1][y1]==1){
                        int celln = x*m+y;
                        int adjcelln = x1*m+y1;
                        if(ds.findUPar(celln)!=ds.findUPar(adjcelln)){
                           ds.UnionBySize(celln,adjcelln); 
                           cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends