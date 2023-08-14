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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ext=0;
        for(auto x:connections){
            if(ds.findUPar(x[1])==ds.findUPar(x[0])){
                ext++;
            }else{
                ds.UnionByRank(x[0],x[1]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)ans++;
        }
				//cout<<"extra cables-"<<ext<<" ans-"<<,
        int count=ans-1;
        if(ext>=count){
            return count;
        }
        return -1;
    }
};