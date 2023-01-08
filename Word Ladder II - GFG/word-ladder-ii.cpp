//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord});
        vector<string> usedlvl;
        //vector<string> path;
        int level =0;
        while(!q.empty()){
            vector<string> s1 = q.front();
            q.pop();
            string str = s1.back();
            
            if(s1.size()>level){
                level++;
                for(auto x:usedlvl){
                    st.erase(x);
                }
                usedlvl.clear();
            }
            if(str==endWord){
                if(ans.size()==0){
                ans.push_back(s1);
                }else if(ans[0].size()==level){
                ans.push_back(s1);
                }
            } 
            
            for(int i=0;i<str.size();i++){
                char ori = str[i];
                for(char d = 'a';d<='z';d++){
                    str[i]=d;
                    if(st.count(str)>0){
                        s1.push_back(str);
                        q.push(s1);
                        usedlvl.push_back(str);
                        s1.pop_back();
                    }
                    
                }
                str[i]=ori;

            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends