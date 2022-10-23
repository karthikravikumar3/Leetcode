class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        }
        vector<pair<int,int>> v;
        for(auto x:mp){
            v.push_back({x.first,x.second});
            
        }
        sort(v.begin(),v.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.second<b.second;});
       for(auto x:v){
           //cout<<x.first<<"-"<<x.second<<endl;
           
       } 
        int res = v.size();
        auto itr=v.begin();
        
        while(itr!=v.end() && k-->0){
             itr->second--;
            if(itr->second==0){
                //cout<<"hello"<<endl;
                
                res--;
                itr++;
               
                
            }
            
     
        }
        return res;
    }
};