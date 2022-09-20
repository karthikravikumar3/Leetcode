class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        
        sort(nums.begin(),nums.end());
        int a=0;
        while(a!=nums.size()-1){
            int b=a+1,c=nums.size()-1;
                while(b<c){
                   
                    if(nums[a]+(nums[b]+nums[c])==0 && (a==0 ||(a>0 && nums[a]!=nums[a-1]))){
                        
                        vector<int> s1;
                        s1.push_back(nums[a]);
                        s1.push_back(nums[b]);
                        s1.push_back(nums[c]);
                        sol.push_back(s1);
                        while(b<c && nums[b]==nums[b+1])b++;
                        while(b<c && nums[c]==nums[c-1])c--;
                    }
                    if(-nums[a]>(nums[b]+nums[c])){
                        b++;
                    }else{
                        c--;
                    }
                }
            a++;
        }
        return sol;
    }
};