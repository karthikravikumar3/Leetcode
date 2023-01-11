//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>> adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        vector<int> count(n,0);
        pq.push({0,0});
        //map<int,int> mp;
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        dist[0]=0;
        count[0]=1;
        int mod=(int)(1e9+7);


        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            //cout<<"node-"<<node<<endl;
            
            for(auto x:adj[node]){
                
                int newn = x.first;
                int ndis = x.second;
                if(dist[newn]>dist[node]+ndis){
                    count[newn]=count[node];
                    dist[newn]=dist[node]+ndis;
                    pq.push({dist[newn],newn});
                }
                else if(dist[newn]==dist[node]+ndis){
                    count[newn]=(count[newn]+count[node])%mod;
                }
                
                //cout<<"ndis-"<<ndis<<" newn-"<<newn<<endl;
                //cout<<"ndis-"<<ndis<<endl;
                //if(vis[newn]>time+ndis){
                    //vis[newn]=time+ndis;
                
                    //cout<<"updated with dis-"<<vis[newn]<<endl;
                
            }
        }

        
        return count[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends