//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> vec(K);
        vector<int> indegree(K,0);
        for(int i=0;i<N-1;i++){
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
                if(dict[i][j]!=dict[i+1][j]){
                    vec[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    //cout<<"loo";
                    indegree[dict[i+1][j]-'a']++;
                    break;
                }
            }
        }
        //cout<<"ll";
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //cout<<"hi1";
        //cout<<"qtop - "<<q.front();
        string z="";
        while(!q.empty()){
            
            int a = q.front();
            q.pop();
            //cout<<"a-"<<a<<endl;
            indegree[a]--;
            z+='a'+a;
            for(auto x:vec[a]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        //cout<<"hi2";
        //cout<<q.size();
        //cout<<z;
        return z;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends