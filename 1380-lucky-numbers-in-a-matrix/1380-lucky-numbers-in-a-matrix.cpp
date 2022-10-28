class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> r;
        set<int> c;
        for(int i=0;i<matrix.size();i++){
            r.insert(*min_element(matrix[i].begin(),matrix[i].end()));
        }
        //cout<<"h1";
        for(int j=0;j<matrix[0].size();j++){
        int mx=0;
        for(int i=0;i<matrix.size();i++){
        
                if(mx<matrix[i][j]){
                    mx=matrix[i][j];
                }
             }            
                c.insert(mx);
        }
        //cout<<"here";
         //set<int> v;
        
         //auto it = set_union(r.begin(),r.end(),c.begin(),c.end(),inserter(v,v,begin());
        vector<int> z;
        for(auto x:r){
            if(c.find(x)!=c.end()){
            z.push_back(x);
            }
        }
        return z;
    }                 
};