class DisjointSet {
    
public:
vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};


class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size()+1);
        int a1,b1;
        for(auto x:edges){
            //cout<<"par-"<<ds.findUPar(x[0])<<"-"<<ds.findUPar(x[1])<<endl;
            
            if(ds.findUPar(x[0])==ds.findUPar(x[1])){
                //cout<<"here"<<endl;
                a1=x[0];
                b1=x[1];
            }else{
                //cout<<"nh"<<endl;
                ds.unionByRank(x[0],x[1]);
            }
            
            //ds.UnionByRank(x.first.x.second);
        }
        
        return {a1,b1};
    }
};