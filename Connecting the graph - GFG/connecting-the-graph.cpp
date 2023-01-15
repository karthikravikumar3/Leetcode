//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
public:
	vector<int> rank,size,parent;


	DisjointSet(int n){
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++)parent[i]=i;

	}

	int findUPar(int node){
		if(parent[node]==node)return node;
		return parent[node] =findUPar(parent[node]);
	}

	void UnionByRank(int NodeU,int NodeV){
		int ulp_u=findUPar(NodeU);
		int ulp_v=findUPar(NodeV);
		if(findUPar(NodeU)==findUPar(NodeV))return;
		if(rank[NodeU]>rank[NodeV]){
			parent[ulp_v]=ulp_u;
		}
		else if(rank[NodeU]<rank[NodeV]){
			parent[ulp_u]=ulp_v;
		}
		else{
			parent[ulp_v]=ulp_u;
			rank[ulp_u]+=1;
		}

	}
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        //vector<int> nvis(n);
        int ext=0;
        for(int i=0;i<edge.size();i++){
            
            if(ds.findUPar(edge[i][0])==ds.findUPar(edge[i][1])){
                ext++;
            }else{
                ds.UnionByRank(edge[i][0],edge[i][1]);
            }
        }
        //vector<int> vis(n);
        //cout<<"ext-"<<ext;
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                count++;
            }
        }
        int ans = count-1;
        if(ext>=ans){
            
            return ans;
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
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends