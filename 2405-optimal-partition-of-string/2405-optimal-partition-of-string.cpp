class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        map<char,int> mp1;
        int count=0;
        
        for(auto x:s){
            mp1[x]++;
        }
        if(mp1.size()==1){
            return s.size();
        }
        for(auto x:s){
            mp[x]++;
            if(mp[x]>1){
                mp.clear();
                mp[x]++;
                count++;
            }
           
        }
        if(count==0){
            return 1;
        }
        return count+1;
    }
};