class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()<3){
           return max(nums[0],nums[1]);
       }
        int dp1[nums.size()-1];
        memset(dp1,0,sizeof(dp1));
        int dp2[nums.size()-1];
        memset(dp2,0,sizeof(dp2));
        dp1[0]=nums[0];
        
        dp2[0]=nums[1];
        dp1[1]=max(nums[1],dp1[0]);
        dp2[1]=max(nums[2],dp2[0]);
        for(int i=2;i<nums.size()-1;i++){
            dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
        }
        for(int i=3;i<nums.size();i++){
            dp2[i-1]=max(nums[i]+dp2[i-3],dp2[i-2]);
        }
        /*for(auto x:dp){
            cout<<x<<"|";
        }*/
       
        
        
           
        return max(dp1[nums.size()-2],dp2[nums.size()-2]);
    }
};