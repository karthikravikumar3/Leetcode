class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        vector<pair<int,int>> pp;
        vector<int> v;
        for(auto x:intervals){
            if((newInterval[0]>=x[0] && newInterval[0]<=x[1])||(newInterval[1]>=x[0] && newInterval[1]<=x[1]) ||(newInterval[1]>=x[1] && newInterval[0]<=x[0])){
                pp.push_back(make_pair(x[0],x[1]));
            }else{
                
                v.push_back(x[0]);
                v.push_back(x[1]);
                sol.push_back(v);
                v.clear();
                
            }
        }
        pp.push_back(make_pair(newInterval[0],newInterval[1]));
        int m1=newInterval[0];
        int m2=newInterval[1];
        for(auto x:pp){
            m1=min(x.first,m1);
            m2=max(x.second,m2);
            //cout<<x.first<<"-"<<x.second<<endl;
        }
        
        vector<int> q;
        q.push_back(m1);
        q.push_back(m2);
        sol.push_back(q);
        sort(sol.begin(),sol.end());
        return sol;
    }
};