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
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        DisjointSet ds(details.size());
        vector<vector<string>> vec(details.size());
        unordered_map<string,int> mp;
        //cout<<"h1";
        for(int i=0;i<details.size();i++){
            for(int j=1;j<details[i].size();j++){
                if(mp.find(details[i][j])==mp.end()){
                    //cout<<"hella"<<endl;
                    mp[details[i][j]]=i;
                }else{
                    //auto p = mp.find(details[i][j]);
                    ds.UnionBySize(i,mp[details[i][j]]);
                }
            }
        }
        for(auto it:mp){
            int node = ds.findUPar(it.second);
            string mail = it.first;
            //cout<<"mail - "<<mail<<" node-"<<node<<endl; 
            
            vec[node].push_back(mail);
            
        }
        vector<vector<string>> ans;
        for(int i=0;i<details.size();i++){
            if(vec[i].size()==0) continue;
            sort(vec[i].begin(),vec[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            
            for(auto x:vec[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end(),greater<vector<string>>());
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends