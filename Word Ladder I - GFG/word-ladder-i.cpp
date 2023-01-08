//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){

            pair<string,int> p = q.front();
            q.pop();
            st.erase(p.first);
            if(p.first==endWord) return p.second;
            for(int i=0;i<p.first.size();i++){
                string s = p.first;
                for(char ch = 'a';ch <= 'z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,p.second+1});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends