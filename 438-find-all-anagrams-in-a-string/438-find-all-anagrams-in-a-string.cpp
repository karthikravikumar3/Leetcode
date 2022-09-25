class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> sol;
        if(p.size()>s.size()){
            return sol;
        }
        int arr[26]={0};
        for(char c:p){
            arr[c-'a']++;
        }
        for(int i=0;i<p.size();i++){
            arr[s[i]-'a']--;
        }
        bool match=true;
        for(auto x:arr){
            if(x!=0){
                match=false;
            }
        }
        if(match)sol.push_back(0);
        int i=0,j=p.size()-1;
        while(j<s.size()-1){
            arr[s[i]-'a']++;
            j++;
            i++;
            arr[s[j]-'a']--;
            
            bool match=true;
            for(auto x:arr){
                if(x!=0){
                    match=false;
                }
            }
            if(match)sol.push_back(i);
        }
        return sol;
    }
};