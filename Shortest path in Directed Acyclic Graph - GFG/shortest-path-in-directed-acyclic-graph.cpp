//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<int> &vis,int i, stack<int> & st,vector<vector<pair<int,int>>> &v){
        vis[i]=1;
        //cout<<"node - "<<i<<endl;
        for(auto x: v[i]){
            //cout<<"unvisited neighbor -"<<x.first<<endl;
            if(!vis[x.first]){
                //cout<<"neighbor-"<<x.first<<endl;
                dfs(vis,x.first,st,v);
            }
            
        }
        //cout<<"node pushed - "<<i<<endl;
        st.push(i);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> v(N);
        for(int i=0;i<M;i++){
            for(int j=0;j<edges[i].size();j++){
                v[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            }
        }
        stack<int> st;
        vector<int> vis(N,0);
        vector<int> mindis(N,1e9);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(vis,i,st,v);
            }
        }
        mindis[0]=0;
        //cout<<st.size();
        while(!st.empty()){
            int a = st.top();
            st.pop();
            for(auto x:v[a]){
                if(mindis[a]+x.second<mindis[x.first]){
                    mindis[x.first]=mindis[a]+x.second;
                }
                
            }
            
        }
        for(auto &x:mindis){
            if(x==1e9){
                x=-1;
            }
        }
        
        return mindis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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