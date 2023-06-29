class Solution {
public:
    vector<vector<int>> v;
    //set<vector<int>> v2;
    void rec(vector<int>& candidates, int target, int ind,vector<vector<int>> &v , vector<int> &v1,int sum){
        if(sum==target && ind==candidates.size()){
            
                v.push_back(v1);
            
            
        }
        if(ind==candidates.size() || sum>target){
            return;
        }
        
        
            
                sum+=candidates[ind];
                v1.push_back(candidates[ind]);
                
                rec(candidates,target,ind,v,v1,sum);
                v1.pop_back();
            sum-=candidates[ind];
            
            
            rec(candidates,target,ind+1,v,v1,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v1;
        rec(candidates,target,0,v,v1,0);
        //vector<vector<int>> v2(v.begin(),v.end());
        return v;
    }
};