//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> v(N);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        vector<int> vis(N,1e9);
        q.push({src,0});
        vis[src]=0;
        while(!q.empty()){
            pair<int,int> a = q.front();
            q.pop();
            for(auto x:v[a.first]){
                if(vis[x]>a.second+1){
                    vis[x]=min(vis[x],a.second+1);
                    q.push({x,a.second+1});
                }
                
            }
        }
        for(auto &x:vis){
            if(x==1e9){
                x=-1;
            }
        }
        return vis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends