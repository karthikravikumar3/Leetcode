//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> parent(n+1);
        for(int i=0;i<parent.size();i++)parent[i]=i;
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,
        vector<pair<int,int> >,greater<pair<int,int>>> pq;
        pq.push({0,1});
        dist[1]=0;
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for(auto x:adj[node]){
                if(dist[x.first]>dis+x.second){
                    parent[x.first]=node;
                    dist[x.first]=dis+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        vector<int> p;
        int n1 = n;
        p.push_back(n1);
        while(n1!=1){
        n1=parent[n1];
        p.push_back(n1);    
        }
        reverse(p.begin(),p.end());
        return p;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends